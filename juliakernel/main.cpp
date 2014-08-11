/*
* Artificial Intelligence v 1.1
* http://juliabot.com/julia/ 
* https://github.com/ruslancheb/juliakernel/ 
* Apache license
*/
///List including libraries
#include "libs.h"
using namespace std;
///Global variables and arrys , options
#include "globals.cpp"
//Functions http-server for input-output
#include "server.cpp"
//Functions for working with audio-stream
#include "sound.cpp"
///Local functions  program "Julia"
#include "functions.cpp"

//std::mutex g_lock; 

///Entry point
int main(int argc, char *argv[])
{
//Sound init begin
	int  play_buf_size = 44100;
	const unsigned int frequ=44100;
	ALshort *input_audio[frequ];
	ALshort *output_audio[frequ];
 	std::thread sound_thread(WorkWithSound,std::ref(input_audio),std::ref(output_audio));
 	sound_thread.detach();
//Sound init end

//Server init begin

    struct sockaddr_in clientaddr;
    socklen_t addrlen;
    char c;
    //Default Values PATH = ~/ and PORT=10000
    char PORT[6];
    ROOT = getenv("PWD");
    strcpy(PORT,"55571");
    strcpy(ROOT,"/home/");
    int slot=0;
    printf("Server started at port no. %s%s%s with root directory as %s%s%s\n","\033[92m",PORT,"\033[0m","\033[92m",ROOT,"\033[0m");
    // Setting all elements to -1: signifies there is no client connected
    for (int i2=0; i2<CONNMAX; ++i2)
        clients[i2]=-1;
    startServer(PORT);

//Server init end

	int mode=1;
	std::string mode_ext;
	std::string html,html_output;
	//Get current directory
	char cwd[1024];
        getcwd(cwd, sizeof(cwd));
	string current_dir(cwd);
	//Exit function
	atexit (bye);
	//Вывод информационно-инициализирующих строк
	printf("%sИскуственный Интеллект\n%s",RED,RESET);
	printf("Инициализация...\n");
	printf("Процессоров в компьютере: %d\n", omp_get_num_procs());
 	struct sysinfo info;
 	sysinfo(&info);
  	printf("Общее количество оперативной памяти: %lu MB\n",  info.totalram/(1024*1024));
  	printf("Объём доступной памяти: %lu MB\n",info.freeram/(1024*1024));
	printf("Объем файла подкачки: %lu MB\n",info.totalswap/(1024*1024));
  	//printf("Объём свободной памяти радела подкачки: %lu MB\n", info.freeswap/(1024*1024));

	//Переведенная в строковой тип иттерация основного скрипта
 	string s;
	//ID клавиши которая будет нажиматься в основном цикле
	int act=2;
	map <int,string> act_mas;
	//Время нажатия клавиш
	float time_action=0.1;
 
	map< string, map< int, map< int, int  >  > >  structurs;
	//Временный массив для сохранения шаблонов
	int** temp_patterns = new int*[100000];
	for(int ib = 0; ib <100000; ++ib)temp_patterns[ib] = new int[10];
	//Массив со структурами и менеджер памяти для этого массива
	std::tr1::hash<std::string> hash_fn;
	int pattern_array_size=(info.freeram-(700*1024*1024))/((int)sizeof(pattern)*100)-2000;
	if(pattern_array_size<10)
	{
		std::cout<<"Недостачно свободной оперативной памяти для работы программы (size="<<pattern_array_size<<")" << endl;
		exit(0);
	}
	else
	{
		std::cout<<"Будет выделена память для "<<pattern_array_size<<" шаблонов" << endl;
	}

	//2D array for object pattern
	pattern ** patterns=new pattern * [pattern_array_size];

	for(int iz=0;iz<pattern_array_size;iz++)
	{
	patterns[iz]=new pattern[10];
		for(int ji=0;ji<10;ji++)
		{
			patterns[iz][ji].i=0;
			patterns[iz][ji].x=0;
			patterns[iz][ji].y=0;
			patterns[iz][ji].d1=0;
		}
	}
	
	printf("%sПривет.Меня зовут Юля\n%s",GREEN,RESET);

	//Команда ОС - Закрыть другие окна с игрой
	exec("killall fceux");
	//Ждать одну секунду
	sleeping(1);
	//Команда ОС - Запуск игры
	exec("fceux "+current_dir+"/input/nintendo_games/Mario.nes");
	//Команда ОС - Активация окна с игрой
 	exec("wmctrl -a 'FCEUX 2.2.1'");
	//Ждать 3 секунды
	sleeping(3);
	//Команда ОС - Нажатие Enter
	action(5,time_action);
	//Ждать 3 секунды
	sleeping(4);
	//Main loop
	
	for(int i=1;i<=99;++i)
	{
	
		//Work with sound
		for(int copy=0; copy<play_buf_size; ++copy) output_audio[copy] = input_audio[copy];
		//Os command line command - Ativation window with game
 		exec("wmctrl -a '"+windowname+"'");
		act=rand() % 3;   
		int time_duration=rand() % 5;   
		//Совершение выбранного переменной act действия в течении времени time
		action(act,time_action*time_duration);
		//Convert i to string
		s=convert::to_string(i);
		//Get image data
		
		switch(mode) {
		case 1:
			{
			 mode_ext="png";
			//Save screen from window game in image and array buffer
			get_screen(s);
			}
		  break;
		case 2:
			{
			 mode_ext="bmp";
			//Load testing images
			string bmpname="input/"+s+".bmp";
			//Load in image buffer - file image
			loadBMP(bmpname);
			}
		  break;
		default:
			{
		  	cout<<"Not set mode"<<endl;
		  	exit(0);
			}
		  break;
		}
		
 		mode_ext="png";
		//Save screen from window game in image and array buffer
		get_screen(s);
		//Output html code
		html="<font color='blue'><small>Кадр "+s+"</font></small><br>";
		html+="<img width='100' height='100' src='../juliakernel/output/"+s+"."+mode_ext+"'><br>";
		html+="Шаблоны<small>("+convert::to_string(limit)+")</small>";
  		//ti=clock();
		
		int limit_i=1;
    		for (int x1=0;x1<nwidth;++x1) {
			for (int y1=0;y1<nheight;++y1) {
				//Лучше брать из начала цикла с помощью флага - хотя нет ,если точка учитывает саму себя
				iterration=0;
				int MINX=0;
				int MINY=0;
				int MINDX=0;
				int MINDY=0;
				//Нахождение структур			       
				//#pragma omp parallel for
			       for (int x2=0;x2<nwidth;++x2){
					for (int y2=0;y2<nheight;++y2) {
					 //От шумов
					 if(
					 abs(pixels_image[x1][y1][0]-pixels_image[x2][y2][0])==0 and 
					 abs(pixels_image[x1][y1][1]-pixels_image[x2][y2][1])==0 and 
					 abs(pixels_image[x1][y1][2]-pixels_image[x2][y2][2])==0
					 )
					 {
					 int r=pixels_image[x1][y1][0];
					 int g=pixels_image[x1][y1][1];
					 int b=pixels_image[x1][y1][2];
					 int delx=x1-x2;
					 int dely=y1-y2;

					 //Вычисление минимальных значений переменной
					   if(delx<MINDX){MINDX=delx;MINX=x1;}
					   if(dely<MINDY){MINDY=dely;MINY=y1;}
					 //Запись обработанной инфорации					 
					 //Цвет
 					 temp_patterns[iterration][0]=r;
 					 temp_patterns[iterration][1]=g;
 					 temp_patterns[iterration][2]=b;
					 //Координаты
					 temp_patterns[iterration][3]=delx;
					 temp_patterns[iterration][4]=dely;

					 iterration++;

					 }

					}
				}
				//Определение относительных координат и запись возможной структуры от левого верхнего угла
				//Нахождение структур
				//Найти функции прямых и кривых внутри структур (Ньютонова интерполяция)
				//Можно добавить и создание ключа в цикл
				string object="";
				for(int iter11=0;iter11<iterration;++iter11)
				{
					int x11=temp_patterns[iter11][3]-MINDX;
					int y11=temp_patterns[iter11][4]-MINDY;	

					temp_patterns[iter11][3]=x11;
					temp_patterns[iter11][4]=y11;

					object+=convert::to_string(x11);
					object+=convert::to_string(y11);
				}
				int dx=0;int dy=0;int poly_x=0;
				//Запись новой структуры
				//Архитектура памяти: Определение коллизий -> Выделение памяти -> Cвязный список для коллизий
				//Вычисление функции движения и появления ,на очереди : уменьшения ,увеличения, поворота - комбинации
				//изменения цвета,3d поворота

				
				//Работа с масивом
		
				size_t str_hash = hash_fn(object+convert::to_string(i));
				int key=(str_hash%pattern_array_size)-1;//Вычисление ключа массива

				int pattern_size=patterns[key][0].i;
				patterns[key][0].i++;
				
				patterns[key][pattern_size].i=i;
				patterns[key][pattern_size].x=MINX;
				patterns[key][pattern_size].y=MINY;
				memcpy(&patterns[key][pattern_size].pattern,object.c_str(),100);
				//Конец работы с массивом
				//Движения по x
				double xnewton[pattern_size],ynewton[pattern_size];
				//Движения по y
				double xnewton2[pattern_size],ynewton2[pattern_size];
				//Появления и исчезновения
				double xnewton3[pattern_size],ynewton3[pattern_size];
				for(int i8=1;i8<pattern_size;i8++)
				{
				ynewton[i8]=patterns[key][i8].x;
				xnewton[i8]=i8;

				ynewton2[i8]=patterns[key][i8].y;
				xnewton2[i8]=i8;

				ynewton3[i8]=patterns[key][i8].i;
				xnewton3[i8]=i8;						
				}
				//Вычисление функций
				polynomialfit(NP, DEGREE, xnewton, ynewton, coeff);
				polynomialfit(NP, DEGREE, xnewton2, ynewton2, coeff2);
				polynomialfit(NP, DEGREE, xnewton3, ynewton3, coeff3);
				//Работа с масивом Можно union
				//Push double values in array
				memcpy(&patterns[key][0].pattern[0],&coeff[0],sizeof(double));
				memcpy(&patterns[key][0].pattern[8],&coeff[1],sizeof(double));
				memcpy(&patterns[key][0].pattern[16],&coeff[2],sizeof(double));
				memcpy(&patterns[key][0].pattern[24],&coeff2[0],sizeof(double));
				memcpy(&patterns[key][0].pattern[32],&coeff2[1],sizeof(double));
				memcpy(&patterns[key][0].pattern[40],&coeff2[2],sizeof(double));
				memcpy(&patterns[key][0].pattern[48],&coeff3[0],sizeof(double));
				memcpy(&patterns[key][0].pattern[56],&coeff3[1],sizeof(double));
				memcpy(&patterns[key][0].pattern[64],&coeff3[2],sizeof(double));

				patterns[key][0].x=pattern_size;
				patterns[key][0].y=pattern_size;
				patterns[key][0].d1=pattern_size;
				//Конец работы с массивом
				


				//Вывод изображений шаблонов и информации о них
				string number_image=render_square_image(temp_patterns,iterration,"");
				if(limit_i<=limit)
				{
				html+="<div><img src='../juliakernel/output/images/"+number_image+".bmp' width='100' height='100'></div>";
				html+="<small>";
				html+="Движение по x<br>";
				if(round(coeff[2])!=0)html+=convert::to_string(round(coeff[2]))+"*x<sup><small>2</small></sup>";
				if(round(coeff[1])!=0)html+="+"+convert::to_string(round(coeff[1]))+"*x";		
				if(round(coeff[0])!=0)html+="+"+convert::to_string(round(coeff[0]))+"";
				
				html+="<br>";
				html+="Движение по y<br>";
				if(round(coeff2[2])!=0)html+=convert::to_string(round(coeff2[2]))+"*x<sup><small>2</small></sup>";
				if(round(coeff2[1])!=0)html+="+"+convert::to_string(round(coeff2[1]))+"*x";		
				if(round(coeff2[0])!=0)html+="+"+convert::to_string(round(coeff2[0]))+"";
				
				html+="<br>";
				html+="Наличие<br>";
				if(round(coeff3[2])!=0)html+=convert::to_string(round(coeff3[2]))+"*x<sup><small>2</small></sup>";
				if(round(coeff3[1])!=0)html+="+"+convert::to_string(round(coeff3[1]))+"*x";		
				if(round(coeff3[0])!=0)html+="+"+convert::to_string(round(coeff3[0]))+"";
				html+="<br></small>";
				}

				limit_i++;
				
				
			}
    		}

	//Compute future state (Newton interpolation) - а потом в завимости от нажатия клавиш 
	//int future_pixels_image[nwidth][nheight][3];
	
	if(i==5)
	{
		int future_limit=10;
		for(int future_i2=0;future_i2<future_limit;future_i2++)
		{
			//Render - Bust structurs
			for(int future_i=0;future_i<pattern_array_size;future_i++)
			{
			int offset_x=patterns[future_i][0].x+future_i2;//Offset x
			int offset_y=patterns[future_i][0].y+future_i2;//Offset y
			int offset_d=patterns[future_i][0].d1+future_i2;//Offset d - disappearance
			//Pull double values from array
			memcpy(&coeff_f[0],&patterns[future_i][0].pattern[0],sizeof(double));
			memcpy(&coeff_f[1],&patterns[future_i][0].pattern[8],sizeof(double));
			memcpy(&coeff_f[2],&patterns[future_i][0].pattern[16],sizeof(double));
			memcpy(&coeff2_f[0],&patterns[future_i][0].pattern[24],sizeof(double));
			memcpy(&coeff2_f[1],&patterns[future_i][0].pattern[32],sizeof(double));
			memcpy(&coeff2_f[2],&patterns[future_i][0].pattern[40],sizeof(double));
			memcpy(&coeff3_f[0],&patterns[future_i][0].pattern[48],sizeof(double));
			memcpy(&coeff3_f[1],&patterns[future_i][0].pattern[56],sizeof(double));
			memcpy(&coeff3_f[2],&patterns[future_i][0].pattern[64],sizeof(double));
			//Compute future pararmeters
			int res=coeff_f[2]*(offset_x^2)+coeff_f[1]*(offset_x^1)+coeff_f[0];//Move x
			int res2=coeff2_f[2]*(offset_y^2)+coeff2_f[1]*(offset_y^1)+coeff2_f[0];//Move y
			//int res3=coeff3_f[2]*(offset_d^2)+coeff3_f[1]*(offset_d^1)+coeff3_f[0];//Disappearance

			//Render image buffer
			for(int pattern_i=0;pattern_i<50;pattern_i++)
			{
			int fx=(int)patterns[future_i][1].pattern[0];
			int fy=(int)patterns[future_i][1].pattern[2];
			future_pixels_image[fx][fy][0]=100;
			future_pixels_image[fx][fy][1]=100;
			future_pixels_image[fx][fy][2]=100;
			};
			}
		//Save frame in image
		string number_image=render_square_image2(future_pixels_image,"video");
		};
	};
	
	//ti = clock() - ti;
        //printf("Time: %f \n", (double)ti/CLOCKS_PER_SEC);
	//Server block start
 	addrlen = sizeof(clientaddr);
        clients[slot] = accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);
        if (clients[slot]<0)perror ("accept() error");
        else
        {
                respond(slot,html);
        }
        while (clients[slot]!=-1) slot = (slot+1)%CONNMAX;
	//Server block end
	}
	return 0;
}
