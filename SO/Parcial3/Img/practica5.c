#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>
#include <png.h>

#define BUFFER_SIZE 1024
#define READ  0
#define WRITE 1

int width, height;
png_byte color_type;
png_byte bit_depth;
png_bytep *row_pointers;

void read_png_file(char *filename) {
  //Abrimos el png para lectura
  FILE *fp = fopen(filename, "rb");
  //Si el png no logró abrirse bien abortamos
  if(!fp) abort();
  //Se crea la estructura para abrir el archivo
  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) abort();
  //se crea la estructura con la info del archivo
  png_infop info = png_create_info_struct(png);
  if(!info) abort();
  //Se crea la memoria que usará el archivo
  if(setjmp(png_jmpbuf(png))) abort();
  //Inicializacmos IO
  png_init_io(png, fp);
  //Leemos la info del archivo
  png_read_info(png, info);
  //Datos del archivo
  width      = png_get_image_width(png, info);
  height     = png_get_image_height(png, info);
  color_type = png_get_color_type(png, info);
  bit_depth  = png_get_bit_depth(png, info);

  // Leer cualquier color_type en profundidad de 8 bits y formato RGBA

  if(bit_depth == 16)
    png_set_strip_16(png);

  if(color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA es siempre profundidad 8 o 16
  if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha(png);

  // Estos tipos de color no tienen canal alfa así que se llenan con 0xff (o null)
  if(color_type == PNG_COLOR_TYPE_RGB ||
     color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

  if(color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);

  png_read_update_info(png, info);

  row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
  for(int y = 0; y < height; y++) {
    row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
  }

  png_read_image(png, row_pointers);

  fclose(fp);
}

void write_png_file(char *filename) {
  int y;

  FILE *fp = fopen(filename, "wb");
  if(!fp) abort();

  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) abort();

  png_infop info = png_create_info_struct(png);
  if (!info) abort();

  if (setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  //Output es de profundidad de 8bits y formato RGBA (evita core dump) e incosistencia de datos
  png_set_IHDR(
    png,
    info,
    width, height,
    8,
    PNG_COLOR_TYPE_RGBA,
    PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_DEFAULT,
    PNG_FILTER_TYPE_DEFAULT
  );

  png_set_expand(png);
  png_write_info(png, info);
  png_write_image(png, row_pointers);
  png_write_end(png, NULL);

  for(int y = 0; y < height; y++) {
    free(row_pointers[y]);
  }
  free(row_pointers);

  fclose(fp);
}

void process_png_file_red(){

	png_byte RED[] = {255,0,0};
	png_byte BLACK[] = {0,0,0};
  	png_byte WHITE[] = {255,255,255};
  	png_byte GRAY70[] = {70,70,70};
  	png_byte GRAY80[] = {80,80,80};
	png_byte GRAY90[] = {90,90,90};
	png_byte GRAY100[] = {100,100,100};
	png_byte GRAY110[] = {110,110,110};
	png_byte GRAY120[] = {120,120,120};

  	for (unsigned int y = 0; y < height; y++) {
    	png_bytep row = row_pointers[y];
    	for (unsigned int x = 0; x < width; x++) {
      		png_bytep px = &(row[x * 4]);

      		for(int i = 0; i < 3; ++i){
        		if(px[i] != BLACK[i] && px[i] != WHITE[i] && px[i] != GRAY70[i] && px[i] != GRAY80[i] && px[i] != GRAY90[i] && px[i] != GRAY100[i] && px[i] != GRAY110[i] && px[i] != GRAY120[i])
		        	px[i] = RED[i];
    		}     
        }

	}
}

void process_png_file_green(){

	png_byte GREEN[] = {0,255,0};
	png_byte BLACK[] = {0,0,0};
  	png_byte WHITE[] = {255,255,255};
  	png_byte GRAY70[] = {70,70,70};
  	png_byte GRAY80[] = {80,80,80};
	png_byte GRAY90[] = {90,90,90};
	png_byte GRAY100[] = {100,100,100};
	png_byte GRAY110[] = {110,110,110};
	png_byte GRAY120[] = {120,120,120};

  	for (unsigned int y = 0; y < height; y++) {
    	png_bytep row = row_pointers[y];
    	for (unsigned int x = 0; x < width; x++) {
      		png_bytep px = &(row[x * 4]);

      		for(int i = 0; i < 3; ++i){
        		if(px[i] != BLACK[i] && px[i] != WHITE[i] && px[i] != GRAY70[i] && px[i] != GRAY80[i] && px[i] != GRAY90[i] && px[i] != GRAY100[i] && px[i] != GRAY110[i] && px[i] != GRAY120[i])
		        	px[i] = GREEN[i];
    		}     
        }

	}
}

void process_png_file_blue(){

	png_byte BLUE[] = {0,0,255};
	png_byte BLACK[] = {0,0,0};
  	png_byte WHITE[] = {255,255,255};
  	png_byte GRAY70[] = {70,70,70};
  	png_byte GRAY80[] = {80,80,80};
	png_byte GRAY90[] = {90,90,90};
	png_byte GRAY100[] = {100,100,100};
	png_byte GRAY110[] = {110,110,110};
	png_byte GRAY120[] = {120,120,120};

  	for (unsigned int y = 0; y < height; y++) {
    	png_bytep row = row_pointers[y];
    	for (unsigned int x = 0; x < width; x++) {
      		png_bytep px = &(row[x * 4]);

      		for(int i = 0; i < 3; ++i){
        		if(px[i] != BLACK[i] && px[i] != WHITE[i] && px[i] != GRAY70[i] && px[i] != GRAY80[i] && px[i] != GRAY90[i] && px[i] != GRAY100[i] && px[i] != GRAY110[i] && px[i] != GRAY120[i])
		        	px[i] = BLUE[i];
    		}     
        }

	}
}

int main(int argc, char *argv[])
{
	const char *imgname = argv[1];
	const char *imgred = argv[2];
	const char *imggreen = argv[3];
	const char *imgblue = argv[4];
    pid_t pid;
    //Abrimos 4 pipes, una para cada hijo y otra para hablar con el padre.
    int pipeA[2];
    int pipeB[2];
    int pipeC[2];
    int pipeD[2];

	int WriteMsg;
	int ReadMsg;
    //Creamos las pipes
    if (pipe(pipeA) == -1 || pipe(pipeB) == -1 || pipe(pipeC) == -1 || pipe(pipeD) == -1) {
    	fprintf(stderr,"Error de pipe");
    	return -1;
    }

  //Hacemos el fork para cada hijo

    for(int hijo = 0; hijo < 3 ; hijo++){
    	int pid = fork();
    	if(hijo == 0){
			switch(pid){
				case 0:
					WriteMsg = 0;
					read_png_file(argv[1]);
					process_png_file_red();
					write_png_file(argv[2]);
    				printf("Soy el hijo '%d' que pondra la imagen %s en rojo con pid '%d' y con padre '%d'\n",hijo,imgname,getpid(),getppid());
				    close(pipeA[WRITE]);   //close write end, read, and then close read end
				    read(pipeA[READ],&WriteMsg,sizeof(WriteMsg));
				    //printf("child: read value : %c\n", ReadMsg);
				    //WriteMsg+=ReadMsg;
				    close(pipeA[READ]);
				    close(pipeB[READ]);       //close read end, write and then close write end
				    write(pipeB[WRITE],&WriteMsg,sizeof(WriteMsg));
				    //printf("child: writeValue value : %c\n", WriteMsg);
				    printf("El archivo %s queda en rojo.\n", imgred);
				    close(pipeB[WRITE]);
				    exit(0);
			    break;

			  	case -1:
				    fprintf(stderr, "Fork falló");
				    return -1;
			    break;

			  	default:
			  		printf("Soy el padre que enviara la imagen %s: \n",imgname);
			  		//int img = system("display $argv[2]");
			  		WriteMsg = 'a';
				    close(pipeA[READ]);      //close read end, write and then close write end
				    write(pipeA[WRITE],&WriteMsg,sizeof(WriteMsg));    //write to pipe one
				    //printf("Parent: writes char : %c\n", WriteMsg);
				    close(pipeA[WRITE]);
				    close(pipeB[WRITE]);        //close write end, read, and then close read end
				    read(pipeB[READ],&ReadMsg,sizeof(ReadMsg));
				    //printf("Parent: reads value : %c\n", ReadMsg);
				    close(pipeB[READ]);
			    break;
			}
    	}

    	if(hijo == 1){
			switch(pid){
				case 0:
			  		WriteMsg = 1;
					read_png_file(argv[1]);
					process_png_file_green();
					write_png_file(argv[3]);
    				printf("Soy el hijo '%d' que pondra la imagen %s en verde con pid '%d' y con padre '%d'\n",hijo,imgname,getpid(),getppid());
				    close(pipeA[WRITE]);   //close write end, read, and then close read end
				    read(pipeA[READ],&ReadMsg,sizeof(ReadMsg));
				    //printf("child: read value : %c\n", ReadMsg);
				    //WriteMsg+=ReadMsg;
				    close(pipeA[READ]);
				    close(pipeB[READ]);       //close read end, write and then close write end
				    write(pipeB[WRITE],&WriteMsg,sizeof(WriteMsg));
				    //printf("child: writeValue value : %c\n", WriteMsg);
				    printf("El archivo %s queda en verde.\n", imggreen);
				    close(pipeB[WRITE]);
				    exit(0);
			    break;

			  	case -1:
				    fprintf(stderr, "Fork falló");
				    return -1;
			    break;

			  	default:
			  		WriteMsg = 2;
				    close(pipeA[READ]);      //close read end, write and then close write end
				    write(pipeA[WRITE],&WriteMsg,sizeof(WriteMsg));    //write to pipe one
				    //printf("Parent: writes char : %c\n", WriteMsg);
				    close(pipeA[WRITE]);
				    close(pipeB[WRITE]);        //close write end, read, and then close read end
				    read(pipeB[READ],&ReadMsg,sizeof(ReadMsg));
				    //printf("Parent: reads value : %c\n", ReadMsg);
				    close(pipeB[READ]);
			    break;
			}
    	}

    	if(hijo == 2){
			switch(pid){
				case 0:
			  		WriteMsg = 'c';			  		
					read_png_file(argv[1]);
					process_png_file_blue();
					write_png_file(argv[4]);
    				printf("Soy el hijo '%d' que pondra la imagen %s en azul con pid '%d' y con padre '%d'\n",hijo,imgname,getpid(),getppid());
				    close(pipeA[WRITE]);   //close write end, read, and then close read end
				    read(pipeA[READ],&ReadMsg,sizeof(ReadMsg));
				    //printf("child: read value : %c\n", ReadMsg);
				    //WriteMsg+=ReadMsg;
				    close(pipeA[READ]);
				    close(pipeB[READ]);       //close read end, write and then close write end
				    write(pipeB[WRITE],&WriteMsg,sizeof(WriteMsg));
				    //printf("child: writeValue value : %c\n", WriteMsg);
				    close(pipeB[WRITE]);
				    exit(0);
			    break;

			  	case -1:
				    fprintf(stderr, "Fork falló");
				    return -1;
			    break;

			  	default:
			  		WriteMsg = 'a';
				    close(pipeA[READ]);      //close read end, write and then close write end
				    write(pipeA[WRITE],&WriteMsg,sizeof(WriteMsg));    //write to pipe one
				    //printf("Parent: writes char : %c\n", WriteMsg);
				    close(pipeA[WRITE]);
				    close(pipeB[WRITE]);        //close write end, read, and then close read end
				    read(pipeB[READ],&ReadMsg,sizeof(ReadMsg));
				    //printf("Parent: reads value : %c\n", ReadMsg);
				    printf("El archivo %s queda en azul.\n", imgblue);
				    close(pipeB[READ]);
			    break;
			}
    	}
    }

	for (int hijo = 0; hijo < 3; hijo++) {
	    int status;
	    pid_t pid = wait(&status);
	}

	int red = system("display red.png");
	int green = system("display green.png");
	int blue = system("display blue.png");

  return 0;
}