

const int BUF_COUNT = 5;

class SoundManager {
    ALCdevice * in_device;
    ALCdevice * out_device;
    ALCcontext * context;
    ALuint al_source;
    ALuint al_buffers[BUF_COUNT];
    ALshort *play_buf[44100];

    int read_buf_size;
    int play_buf_size;
    ALenum  error ;
public:
    SoundManager() {
        error = 0;
        read_buf_size = 44000;
        play_buf_size = 44000;
        play_buf[0] = 0;

        // Инициализируем OpenAL и создаем всякие штучки
        out_device = alcOpenDevice (0);
        context = alcCreateContext(out_device, 0);
        alcMakeContextCurrent(context);

        const char * szDefaultCaptureDevice = alcGetString(NULL, ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER);
	/*
		while(*szDefaultCaptureDevice)
		{
 		ALFWprintf("%s\n", pDeviceList);
        	pDeviceList += strlen(pDeviceList) + 1;
		std::cout<<"Capture devices:  "<< szDefaultCaptureDevice <<std::endl ;
		szDefaultCaptureDevice += strlen(szDefaultCaptureDevice) + 1; //next device
		}
	*/
        in_device = alcCaptureOpenDevice (szDefaultCaptureDevice, 44100, AL_FORMAT_STEREO16, read_buf_size);
        if( (error=  alcGetError(in_device)) != AL_NO_ERROR)
            std::cout<<error<<" alcCaptureOpenDevice "<<__LINE__<<"\n";
        alGenSources(1, &al_source);
        alGenBuffers(BUF_COUNT, al_buffers);

        // Заполняем первую очередь
        for (int i = 0; i < BUF_COUNT; ++i) {
            alBufferData(al_buffers[i], AL_FORMAT_MONO16, play_buf, play_buf_size * sizeof(ALshort), play_buf_size);
        }
        // Здесь начинаем запись и воспроизведение
        alSourceQueueBuffers(al_source, BUF_COUNT, al_buffers);
        alSourcePlay(al_source);
        alcCaptureStart(in_device);
        if( (error=  alcGetError(in_device)) != AL_NO_ERROR)
            std::cout<<error<<" alcCaptureStart "<<__LINE__<<"\n";
    }
    void input(ALshort ** input_audio,ALshort ** output_audio) {
        ALint samples, val, state;
        // Если источник вдруг перестал играть, то пнем его
        alGetSourcei (al_source, AL_SOURCE_STATE,  &state);
        if (state != AL_PLAYING) alSourcePlay(al_source);

        alcGetIntegerv(in_device, ALC_CAPTURE_SAMPLES, sizeof(samples), &samples);
        if( (error=  alcGetError(in_device)) != AL_NO_ERROR)
            //std::cout<<error<<" alcGetIntegerv "<<__LINE__<<"\n";
        alGetSourcei (al_source, AL_BUFFERS_PROCESSED , &val);
	
        while ( ( (val--) > 0) && (samples < play_buf_size)   ) {
            ALuint buffer;
	    //Write sound
            alcCaptureSamples(in_device, play_buf, samples);
	    //-Write sound

	    //Connect with main thread
	    for(int copy=0; copy<play_buf_size; copy++) input_audio[copy] = play_buf[copy];
	    for(int copy=0; copy<play_buf_size; copy++) play_buf[copy] = output_audio[copy];

	    //Play sound 
	    alSourceUnqueueBuffers(al_source, 1, &buffer);
            alBufferData(buffer, AL_FORMAT_STEREO16, play_buf, play_buf_size * sizeof(ALshort), play_buf_size);
            alSourceQueueBuffers(al_source, 1, &buffer);
	    //-Play sound

	    //Write sound
            alcGetIntegerv(in_device, ALC_CAPTURE_SAMPLES, sizeof(samples), &samples);
	    //-Write sound
        }
	
    }
    void process() { }
    ~SoundManager() {
        alcCaptureStop(in_device);
        alcCaptureCloseDevice(in_device);
    }
};


void WorkWithSound(std::string msg,ALshort **input_audio,ALshort **output_audio)
{
    SoundManager s;
    while (1) {
        s.input(input_audio,output_audio);
	//s.output();
    }
}

