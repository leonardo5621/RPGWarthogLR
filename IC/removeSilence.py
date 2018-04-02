import numpy
import scipy.io.wavfile

def removeSilence(file):
    fs,signal=scipy.io.wavfile.read(file)
    frameL=int(fs*0.025)
    numF=int(len(signal)/frameL)

    frames=numpy.ndarray((numF,frameL),numpy.int16)
     
    for k in range(0,numF):
     for i in range(0,frameL):
      if(k*frameL+i<len(signal)):
       frames[k,i]=signal[k*frameL+i,0]
      else:
       frames[k,i]=0

    n=0

    for d in range(0,numF):
     if(abs(max(frames[d,:]))>46):
      n=n+1

    c=-1
    newSignal=numpy.ndarray((n,frameL),numpy.int16)
    for t in range(0,numF):
     if(abs(max(frames[t,:]))>46):
      c=c+1
     for r in range(0,frameL):
      newSignal[c,r]=frames[t,r]

    SoundWithoutSilence=numpy.reshape(newSignal,(newSignal.size,1))
    
    scipy.io.wavfile.write('output.wav',fs,SoundWithoutSilence)
    
       
    
