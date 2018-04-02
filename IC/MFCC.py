import numpy as np
import scipy.io.wavfile
from scipy.fftpack import dct

def Mfcc(file):

    #Leitura do Sinal

    SRate,SoundSignal= scipy.io.wavfile.read(file)

    
    empSignal = np.append(SoundSignal[0], SoundSignal[1:] - 0.95 * SoundSignal[:-1])

    # Respectivamente duração do quadro(em segundos) e coeficiente de sobreposição
    FrameSize=0.025
    OverLap=0.01
    
    FrameLength=int(round(SRate*FrameSize))
    FrameStep=int(round(OverLap*SRate))

    SignalLength=len(empSignal)

    #Numero de Quadros para que o sinal seja dividido
    numFrames = int(np.ceil(float(np.abs(SignalLength-FrameLength)) / FrameStep))

    #Ajuste para que todos os quadros tenham um mesmo número de amostras
    pad_signal_length = numFrames*FrameStep + FrameLength
    z = np.zeros((pad_signal_length - SignalLength))
    Total=np.append(empSignal,z)

    #Framing
    indices = np.tile(np.arange(0, FrameLength), (numFrames, 1)) + np.tile(np.arange(0, numFrames * FrameStep, FrameStep), (FrameLength, 1)).T
    frames= Total[indices.astype(np.int32,copy=False)]

    #Janelamento
    frames *= np.hamming(FrameLength)

    #Aplicar a transformada de Fourier de Tempo curto no Sinal
    NFFT=512
    
    mag_frames = np.absolute(np.fft.rfft(frames, NFFT))
    pSpectrum = ((1.0 / NFFT) * ((mag_frames) ** 2))

    #Modelagem do banco de filtros 
    nfilt=40
    sFreq=0
    HighFreq=(2595 * np.log10(1 + (SRate / 2) / 700))

    melScale = np.linspace(sFreq, HighFreq, nfilt + 2)

    hzScale = (700 * (10**(melScale / 2595) - 1))

    bin = np.floor((NFFT + 1) * hzScale / SRate)

    fbank = np.zeros((nfilt, int(np.floor(NFFT/2 + 1))))
    for m in range(1, nfilt + 1):
     f_m_minus = int(bin[m - 1])   
     f_m = int(bin[m])            
     f_m_plus = int(bin[m + 1])    
     for k in range(f_m_minus, f_m):
      fbank[m - 1, k] = (k - bin[m - 1]) / (bin[m] - bin[m - 1])
     for k in range(f_m, f_m_plus):
      fbank[m - 1, k] = (bin[m + 1] - k) / (bin[m + 1] - bin[m])

    #Aplica o Banco de Filtro no Sinal Segmentado
      
    filter_banks = np.dot(pSpectrum, fbank.T)
    filter_banks = np.where(filter_banks == 0, np.finfo(float).eps, filter_banks)

    #Logaritmo do Banco de filtro
    filter_banks = 20 * np.log10(filter_banks)

    num_ceps=12

    #Transformada do Cosseno Discreta

    mfcc = dct(filter_banks, type=2, axis=1, norm='ortho')[:, 1 : (num_ceps + 1)]

    (nframes, ncoeff) = mfcc.shape
    cep_lifter=22
    n = np.arange(ncoeff)
    lift = 1 + (cep_lifter / 2) * np.sin(np.pi * n / cep_lifter)
    mfcc *= lift

    filter_banks -= (np.mean(filter_banks, axis=0) + 1e-8)

    mfcc -= (np.mean(mfcc, axis=0) + 1e-8)

    return mfcc

    
