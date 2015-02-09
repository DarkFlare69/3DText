#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	srvInit();
	aptInit();
	gfxInit();
	hidInit(NULL);

	consoleInit(GFX_TOP, NULL);

int c;
FILE *file;
file = fopen("file.txt", "r");
if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
}

	while (aptMainLoop())
	{
		hidScanInput();

		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
