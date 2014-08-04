///Ньютонова интерполяция - функция
bool polynomialfit(int obs, int degree, double *dx, double *dy, double *store) /* n, p */
{
  gsl_multifit_linear_workspace *ws;
  gsl_matrix *cov, *X;
  gsl_vector *y, *c;
  double chisq;
 
  int i, j;
 
  X = gsl_matrix_alloc(obs, degree);
  y = gsl_vector_alloc(obs);
  c = gsl_vector_alloc(degree);
  cov = gsl_matrix_alloc(degree, degree);
 
  for(i=0; i < obs; i++) {
    gsl_matrix_set(X, i, 0, 1.0);
    for(j=0; j < degree; j++) {
      gsl_matrix_set(X, i, j, pow(dx[i], j));
    }
    gsl_vector_set(y, i, dy[i]);
  }
 
  ws = gsl_multifit_linear_alloc(obs, degree);
  gsl_multifit_linear(X, y, c, cov, &chisq, ws);
 
  /* store result ... */
  for(i=0; i < degree; i++)
  {
    store[i] = gsl_vector_get(c, i);
  }
 
  gsl_multifit_linear_free(ws);
  gsl_matrix_free(X);
  gsl_matrix_free(cov);
  gsl_vector_free(y);
  gsl_vector_free(c);
  return true; /* we do not "analyse" the result (cov matrix mainly)
		  to know if the fit is "good" */
}

///Конвертирование из int в string
namespace convert
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

void sleeping(float seconds)
{
    clock_t goal = seconds*1000000 + clock();
    while (goal > clock());
}



///Выполнение команды операционной системы от имени программы с сохранением результата
std::string exec(std::string cmd) {
	FILE* pipe = popen(cmd.c_str(), "r");
	if (!pipe) return "ERROR";
	char buffer[128];
	std::string result = "";
	/*
	while(!feof(pipe)) {
		if(fgets(buffer, 128, pipe) != NULL)
		result += buffer;
	}
	pclose(pipe);
	*/
	return result;
}

///Перебор множеств подмножества
int pows()
{
    //множество
    int M[4] = {2, 5, 6, 9};
    //кол-во элементов множества
    int w = 4;
 
    int i, j, n;
    n = pow(2, w);
    //перебор битовых маск
    for ( i = 0; i < n; i++ )
    {
        printf("{");
	//перебор битов в маске
        for ( j = 0; j < w; j++ )
	    //если j-й бит установлен
            if ( i & (1 << j) )
 		//--то выводим j-й элемент множества
                printf("%d", M[j]);
        printf("}\n");
    }
    return 0;
}



///Получение объекта окна по его названию в титле
Window windowWithName(Display *dpy, Window top, char *name)
{
	Window *children, dummy;
	unsigned int nchildren;
	unsigned int i;
	Window w = 0;
	char *window_name;

	if (XFetchName(dpy, top, &window_name) && !strcmp(window_name, name))
		return (top);

	if (!XQueryTree(dpy, top, &dummy, &dummy, &children, &nchildren))
		return (0);

	for (i = 0; i < nchildren; i++)
	{
		w = windowWithName(dpy, children[i], name);
		if (w)
			break;
	}
	if (children)
		XFree((char *) children);
	return (w);
}



///Вычисление сдвига при сохранении изображений
int get_shift (int mask) {
      int shift = 0;
      while (mask) {
        if (mask & 1) break;
        shift++;
        mask >>=1;
      }
      return shift;
}


///Сохранение и уменьшение скринота в массив - сохранение изображения
//1)Снятие скриншота с сохранением указателя
//2)Уменьшение изображения по указателю
//3)Сохранение изображение
void get_screen (string filenom)
{
    Display *disp;
    Window root;
    XWindowAttributes watts;
    XImage *image;
    cairo_surface_t *surface;
    unsigned int width;
    unsigned int height;
    int stride;
	/*Глобальная перменная - замер времени выполнения участков кода*/
	
    disp = XOpenDisplay(NULL);
    root = DefaultRootWindow(disp);
    //Взять скрин с окна с именем в заголовке "FCEUX 2.2.1"
    root = windowWithName(disp, root,"FCEUX 2.2.1");
    XGetWindowAttributes(disp, root, &watts);
    width = watts.width;
    height = watts.height;

    image = XGetImage(disp, root, watts.x, watts.y, width, height, AllPlanes,ZPixmap);
    stride = cairo_format_stride_for_width(CAIRO_FORMAT_RGB24, width);
    unsigned char *datapng = (unsigned char *) malloc (stride * height);
	int red_shift= get_shift(image->red_mask);
	int green_shift= get_shift(image->green_mask);
	int blue_shift= get_shift(image->blue_mask);


    //Массив с пикселями изображения
    //map< int ,map <int , map < int, unsigned char > > > in;
	
    for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x) {
		    unsigned long pixel = XGetPixel(image, x, y);
		    unsigned char red = (image->red_mask & pixel) >> red_shift;
		    unsigned char green = (image->green_mask & pixel) >> green_shift;
		    unsigned char blue = (image->blue_mask & pixel) >> blue_shift; 
			/*
			in[y][x][0]=blue;
			in[y][x][1]=green;
			in[y][x][2]=red;
			*/
			//Буффер записи в файл
		    	datapng[y * stride + x * 4 + 0]=blue;
			datapng[y * stride + x * 4 + 1]=green;
			datapng[y * stride + x * 4 + 2]=red;
			in[y][x][0]=red;
			in[y][x][1]=green;
			in[y][x][2]=blue;
		}
	}

    const float tx = float(width) / nwidth;
    const float ty = float(height) / nheight;
    const int components = 3;
    const int bytes_per_row = width * components;

    const int components2 = components;
    const int bytes_per_row2=width * components;

    int a, b, c, d, index;
    unsigned char Ca, Cb, Cc;
    unsigned char C[5];
    unsigned char d0, d2, d3, a0, a1, a2, a3;

    for (int i = 0; i < nheight; ++i)
    {
        for (int j = 0; j < nwidth; ++j)
        {

	    const int x = int(tx * j);
            const int y = int(ty * i);
            const float dx = tx * j - x;
            const float dy = ty * i - y;

            index = y * bytes_per_row + x * components;
            a = y * bytes_per_row + (x + 1) * components;
            b = (y + 1) * bytes_per_row + x * components;
            c = (y + 1) * bytes_per_row + (x + 1) * components;

            for (int k = 0; k < 3; ++k)
            {
                for (int jj = 0; jj <= 3; ++jj)
                {
		//Беруться пиксели из входящего изображения
                    d0 = in[(y - 1 + jj)][(x - 1)][k] - in[(y - 1 + jj)][x][k];

                    d2 = in[(y - 1 + jj)][(x + 1)][k] - in[(y - 1 + jj)][x][k];

                    d3 = in[(y - 1 + jj)][(x + 2)][k] - in[(y - 1 + jj)][x][k];

                    a0 = in[(y - 1 + jj)][x][k];

	       //Вычисляются параметры
                    a1 = -1.0 / 3 * d0 + d2 - 1.0 / 6 * d3;
                    a2 = 1.0 / 2 * d0 + 1.0 / 2 * d2;
                    a3 = -1.0 / 6 * d0 - 1.0 / 2 * d2 + 1.0 / 6 * d3;
                    C[jj] = a0 + a1 * dx + a2 * dx * dx + a3 * dx * dx * dx;

                    d0 = C[0] - C[1];
                    d2 = C[2] - C[1];
                    d3 = C[3] - C[1];
                    a0 = C[1];
                    a1 = -1.0 / 3 * d0 + d2 -1.0 / 6 * d3;
                    a2 = 1.0 / 2 * d0 + 1.0 / 2 * d2;
                    a3 = -1.0 / 6 * d0 - 1.0 / 2 * d2 + 1.0 / 6 * d3;
                    Cc = a0 + a1 * dy + a2 * dy * dy + a3* dy * dy * dy;

		//Буффер записи в файл
		   // datapng[i * stride + j * 4 + k]=Cc;
		//Запись в массив изображения
		    pixels_image[i][j][k]=(int)Cc;
			 
		}
	   }    
         }
      }

    //Сохранение изображения

    string filename;
    filename="output/"+filenom+".png";
    const char*  filename2=filename.c_str();
    surface = cairo_image_surface_create_for_data(
            datapng,
            CAIRO_FORMAT_RGB24,
            width, height,
            stride);
    cairo_surface_write_to_png(
            surface,
	    filename2
            );
    cairo_surface_destroy(surface);
    free(datapng);

}




///Действия
int action(int a,float time)
{
	//Передаем массив нажимаемых кнопок
	//Содержит команды командной строки
        string cmd,cmd2,act,times;
 	FILE *ptr;
	exec("wmctrl -a 'FCEUX 2.2.1'");
        times=convert::to_string(time);
     switch (a)
      {
         case 0:
      	    cmd="";//
	    cmd2="";
	    act="Ничего не делаю в течении "+times+" сек.";
            break;
         case 1:
            cmd= "xdotool keydown Left";
            cmd2="xdotool keyup Left";
	    act="Двигаюсь влево в течении "+times+" сек.";
            break;
         case 2:
      	    cmd= "xdotool keydown f+Left";//Прыжок
	    cmd2= "xdotool keyup f+Left";
            act="Прыгаю в течении "+times+" сек.";
	    break;
         case 3:
      	    cmd= "xdotool keydown Right";
	    cmd2= "xdotool keyup Right";
            act="Двигаюсь вправо в течении "+times+" сек.";
	    break;
         case 4:
      	    cmd= "xdotool keydown Return;";
      	    cmd2="xdotool keyup Return;";
	    act="Нажимаю Enter  в течении "+times+" сек.";
 	    break;

      }
	act=act+"\n";
 	printf(act.c_str());

	//Ввод команды в консоль
	ptr = popen(cmd.c_str(), "r");
	//Вывод информации из консоли
	char buff[512];
  	 while(fgets(buff, sizeof(buff), ptr)!=NULL){
	        printf("%s", buff);
	}
	sleeping(time);
	ptr = popen(cmd2.c_str(), "r");


	return 0;
}

///Вывод информации по типу echo в php - постараюсь сделать типонезависимым - то есть для разных типов своя функция вывода
//Можно сделать шаблон - для map,char* и т д ,либо перезагузка 
void echo(string r)
{
  std::cout << r.c_str() << std::endl;
}

///Создание html-кода для отображения фрагментов или сгенерированных картинок
std::string render_square(int array_pointer[10][10][3])
{
	int width=10;
	int height=10;
	string r,g,b;
	std::string output="";
	output+="<style>.render span{border-collapse:collapse;display:block;width:10px;height:10px;}</style>";
	output+="<div class='render'>";
	for(int x=0;x<width;++x)
	{
		for(int y=0;y<height;++y)
		{
		r = convert::to_string(array_pointer[x][y][0]);
		g = convert::to_string(array_pointer[x][y][1]);
		b = convert::to_string(array_pointer[x][y][2]);
		output+="<span style='line-height:6px;font-size:10px;color:rgb("+r+","+g+","+b+");background:rgb("+r+","+g+","+b+");'>***</span>";
		}
		output+="<br>";
	}
	output+="</div>";
return output;
}

std::string render_square_image(int** temp_patterns,int iter)
{
   const unsigned int dim = 10;

   bitmap_image image(dim,dim);

   for (unsigned int x = 0; x < dim; ++x)
   {
      for (unsigned int y = 0; y < dim; ++y)
      {
         //rgb_store col = jet_colormap[(x + y) % dim];
         image.set_pixel(x,y,(unsigned char)255,(unsigned char)255,(unsigned char)255);
      }
   }

    for (int i = 0; i < iter; ++i)
    {
 	// temp_patterns[i]
	
        image.set_pixel(
	(unsigned int)(9-temp_patterns[i][4]),
	(unsigned int)(9-temp_patterns[i][3]),
	(unsigned char)temp_patterns[i][0],
	(unsigned char)temp_patterns[i][1],
	(unsigned char)temp_patterns[i][2]
	);
	
    }

	std::string fn=convert::to_string(count_images);
        image.save_image("output/images/"+fn+".bmp");
count_images++;
return fn;
}

///Загрузка bmp-изображения в массив
int loadBMP(std::string file_name)
{
 unsigned char red;
 unsigned char green;
 unsigned char blue;
  	 bitmap_image image(file_name);
  	 if (!image)
  	 {
        	printf("Error - Failed to open '%s'\n",file_name.c_str());
  	 }	
		int dim=10;
		  for (unsigned int x = 0; x < dim; ++x)
		   {
		      for (unsigned int y = 0; y < dim; ++y)
		      {
			 image.get_pixel(y,x,red,green,blue);
			 pixels_image[x][y][0]=(unsigned int)red;
			 pixels_image[x][y][1]=(unsigned int)green;
			 pixels_image[x][y][2]=(unsigned int)blue;
		      }
		   }
	return 0;
}



//Разделение строки на подстроки

map <int,string> split(std::string delimiter,std::string s)
{
size_t pos = 0;
std::string token;
map <int,string> tokens;
int i=0;
while ((pos = s.find(delimiter)) != std::string::npos) {
    //std::cout << token << std::endl;
    tokens[i]= s.substr(0, pos);
    i++;
    s.erase(0, pos + delimiter.length());
}
return tokens;
}

void savelog(std::string output)
{
	  std::ofstream myfile;
	  myfile.open ("output/debug.html");//std::ios::app
	  myfile << output << std::endl;
	  myfile.close();
}


