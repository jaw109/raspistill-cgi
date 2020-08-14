#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
	char* szQUERYSTRING = getenv("QUERY_STRING");
	if( (NULL!=szQUERYSTRING) && (0==strcmp(szQUERYSTRING, "help")) )
	{
		printf("Content-Type: text/plain\n\n");

		printf("Usage:\n");

		printf("  shutter=%%d      Set shutter speed in microseconds\n");
		printf("  ISO=%%d          Set capture ISO\n");
		printf("  flicker={...}   Set flicker avoid mode (see Notes)\n");
		printf("  imxfx={...}     Set image effect (see Notes)\n");
		printf("  width=%%d        Set image width <size>\n");
		printf("  height=%%d       Set image height <size>\n");
		printf("  drc={...}       Set DRC Level (see Notes)\n");
		printf("  quality=%%d      Set jpeg quality <0 to 100>\n");

		printf("\n");
		printf("\n");
		printf("Notes:\n");
		printf("  Flicker avoid mode options :\n");
		printf("    off,auto,50hz,60hz\n");
		printf("\n");

		printf("  Image Effect mode options :\n");
		printf("    none,negative,solarise,sketch,denoise,emboss,oilpaint,hatch,gpen,pastel,watercolour,film,blur,saturation,colourswap,washedout,posterise,colourpoint,colourbalance,cartoon\n");
		printf("\n");

		printf("  Dynamic Range Compression (DRC) options :\n");
		printf("    off,low,med,high\n");
		printf("\n");
		printf("\n");

		printf("Example:\n");
		printf("  Use \"raspistill.cgi?width=1920&height=1080&quality=80\" to set the image-width at 1920, image-height at 1080 and jpeg quality at 80 of 100\n");
		printf("  Use \"raspistill.cgi?shutter=10000&ISO=800\" to set the shutter at 10000 micro seconds and ISO at 800\n");

		return 0;
	}

	printf("Content-type: image/jpeg\n\n");

	char* cmd = new char[1024];
	strcpy(cmd, "raspistill --timeout 1 --nopreview -o -");

	if(NULL!=szQUERYSTRING)
	{
		char s[2] = "&";
		char* token = strtok(szQUERYSTRING, s);
		while(token!=NULL)
		{
			char szKEY[64] = {0};
			char szVALUE[64] = {0};
			sscanf(token, "%[^=]=%s", szKEY, szVALUE);
			
			if(strlen(szKEY)>0 && strlen(szVALUE)>0)
			{
				if(0==strcmp(szKEY, "shutter"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --shutter %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}

				if(0==strcmp(szKEY, "ISO"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --ISO %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}

				if(0==strcmp(szKEY, "flicker"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --flicker %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}

				if(0==strcmp(szKEY, "imxfx"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --imxfx %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}

				if(0==strcmp(szKEY, "width"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --width %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}

				if(0==strcmp(szKEY, "height"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --height %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}

				if(0==strcmp(szKEY, "drc"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --drc %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}

				if(0==strcmp(szKEY, "quality"))
				{
					char szAppendCmd[128];
					sprintf(szAppendCmd, " --quality %s", szVALUE);
					strcat(cmd, szAppendCmd);
				}
			}


			token = strtok(NULL, s);
		}
	}

	system(cmd);
	return 0;
}
