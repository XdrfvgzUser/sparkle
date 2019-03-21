#include "were/were_event_loop.h"
#include "platform/na/platform_na.h"
#include "compositor/gl/compositor_gl.h"
#include "common/were_benchmark.h"
#include "sound/sles/sound_sles.h"
#include <sys/stat.h>
#include <stdexcept>

#define SOUND_THREAD

int main(int argc, char **argv)
{
    std::string internalDataPath;

    if(argc == 1){
        were_message("No arguments given.\n");
        return 1;
    } else {
        internalDataPath = argv[1];
    }

    were_message("android_main started.\n");

    umask(0);

    try
    {
        WereEventLoop *loop = new WereEventLoop();
        Platform *platform = platform_na_create(loop);
        Compositor *compositor = compositor_gl_create(loop, platform, internalDataPath + "/sparkle.socket");

#ifdef SOUND_THREAD
        WereEventLoop *loop2 = new WereEventLoop();
        SoundSLES *sound = new SoundSLES(loop2, internalDataPath + "/sparkle-sound.socket");
        loop2->runThread();
#else
        SoundSLES *sound = new SoundSLES(loop, internalDataPath + "/sparkle-sound.socket");
#endif

        WereBenchmark *test = new WereBenchmark(loop);
        compositor->frame.connect(WereSimpleQueuer(loop, &WereBenchmark::event, test));

        platform->start();
        loop->run();
        platform->stop();

        delete sound;
#ifdef SOUND_THREAD
        loop2->exit();
        delete loop2;
#endif
        delete test;
        delete compositor;
        delete platform;
        delete loop;
    }
    catch (const std::exception &e)
    {
        were_error("%s\n", e.what());
    }

    were_message("android_main finished.\n");
    return 0;
}

