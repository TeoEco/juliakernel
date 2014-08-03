/*
* Artificial Intelligence
* http://juliabot.com/julia/ 
*/

//Script create copyies app
//Script response for all
///List including libraries
#include "libs.h"
using namespace std;
///Global variables and arrys , options
#include "globals.cpp"
//Functions http-server for input-output
#include "server.cpp"
//Functions for working with audio-stream
#include "sound.cpp"
///Подключаемые функции программы "Юля"
#include "functions.cpp"

//std::mutex g_lock; 

void bye (void)
{
 printf("\nGoodbye, cruel world....\n%s",RESET);
 exec("killall fceux");
}


 

///Точка входа в программу - начальная функция
int main(int argc, char *argv[])
{
//Sound init begin

	int  play_buf_size = 44000;
	const unsigned int freq=44000;
	ALshort *input_audio[freq];
	ALshort *output_audio[freq];
 	std::thread sound_thread(WorkWithSound,"Hello",std::ref(input_audio),std::ref(output_audio));
 	sound_thread.detach();
	int fori=0;	

//Sound init end


//Server init begin
    struct sockaddr_in clientaddr;
    socklen_t addrlen;
    char c;
    //Default Values PATH = ~/ and PORT=10000
    char PORT[6];
    ROOT = getenv("PWD");
    strcpy(PORT,"55568");
    strcpy(ROOT,"/home/");
    int slot=0;
    printf("Server started at port no. %s%s%s with root directory as %s%s%s\n","\033[92m",PORT,"\033[0m","\033[92m",ROOT,"\033[0m");
    // Setting all elements to -1: signifies there is no client connected
    for (int i2=0; i2<CONNMAX; i2++)
        clients[i2]=-1;
    startServer(PORT);
//Server init end

    
	std::string html,html_output;
	//Get current directory
	char cwd[1024];
        getcwd(cwd, sizeof(cwd));
	string current_dir(cwd);


	//Задание функции выполнющейся при выходе
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
	float time=0.1;
 
	map< string, map< int, map< int, int  >  > >  structurs;
	//Временный массив для сохранения шаблонов
	int** temp_patterns = new int*[100000];
	for(int ib = 0; ib <100000; ++ib)temp_patterns[ib] = new int[10];
	//Массив со структурами и менеджер памяти для этого массива
	std::tr1::hash<std::string> hash_fn;
	int size=(info.freeram-(400*1024*1024))/(int)sizeof(pattern);
	if(size<0)
	{
		std::cout<<"Недостачно свободной оперативной памяти для работы программы (size="<<size<<")" << endl;
		exit(0);
	}
	else
	{
		std::cout<<"Будет выделена память для "<<size<<" шаблонов" << endl;
	}
	
	pattern *patterns=new pattern[size];
	for(int i=0;i<size;i++)
	{
	patterns->i=0;
	patterns->x=0;
	patterns->y=0;
	}
	
	//printf("%sПривет.Меня зовут Юля\n", GREEN);
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
	action(4,time);
	//Ждать 3 секунды
	sleeping(4);



	//Main loop
	for(int i=1;i<=100;++i)
	{
	//Структура цикла 
	//0)Активция окна
	//1)Любое действие или бездействие
	//2)Снятие скриншота с окна
	//4)Уменьшение картинки до 20 * 20 - сохранение
	//5)Передача картинки программе
	//6)Вывод structurs
		//Work with sound
		for(int copy=0; copy<play_buf_size; copy++) output_audio[copy] = input_audio[copy];
		//0)Команда ОС -Активация окна с игрой
 		exec("wmctrl -a '"+windowname+"'");
		//1)Совершение выбранного переменной act действия в течении времени time
		action(act,time);
		//Конвертация итеррации цикла из типа числа в тип строка 
		s=convert::to_string(i);
	//Вывод скришота обрабатываемого
	html="<font color='blue'><small>Кадр "+s+"</font></small><br>";
	html+="<img width='100' height='100' src='../juliakernel/output/"+s+".png'><br>";
	html+="Шаблоны<small>("+convert::to_string(limit)+")</small>";
		//2)3)Снятие скриншота с игры. Внутри функции можно и сохранять и не сохранять в файл скриншот 
		get_screen(s);
		//Get value sound from audio stream
 		//get_mic_sound_buff();
		//Get value sound from os audio stream
		//get_os_sound_buff();
		//Play sound from buffer
		//play_audio_buff();
		//Загрука тестовых изображений
		string bmpname=""+s+".bmp";
		//loadBMP(bmpname);
		//html+=render_square(pixels_image);
		//от 100 000 до 4 000 000 итеррации 
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
			       //#pragma omp parallel for
			       for (int x2=0;x2<nwidth;++x2){
					for (int y2=0;y2<nheight;++y2) {
					 //От шумов
					 if(
					 abs(pixels_image[x1][y1][0]-pixels_image[x2][y2][0])<3 and 
					 abs(pixels_image[x1][y1][1]-pixels_image[x2][y2][1])<3 and 
					 abs(pixels_image[x1][y1][2]-pixels_image[x2][y2][2])<3
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
				//Преобразовать в уникальную строку + (возможно md5) map и записать для неё в массив характеристики
				string object="";
				for(int iter11=0;iter11<iterration;++iter11)
				{
					int x11=temp_patterns[iter11][3]-MINDX;
					int y11=temp_patterns[iter11][4]-MINDY;	

					temp_patterns[iter11][3]=x11;
					temp_patterns[iter11][4]=y11;
					object+=convert::to_string(x11);
					
				}
				int dx=0;int dy=0;int poly_x=0;
				//Запись новой структуры
				//Архитектура памяти: Определение коллизий -> Выделение памяти -> Cвязный список для коллизий
				
				size_t str_hash = hash_fn(object+convert::to_string(i));
				int key=(str_hash%size)-1;//Вычисление ключа массива
				patterns[key].i=i;
				patterns[key].x=MINX;
				patterns[key].y=MINY;
				
				
				//Функции смещений структур (Ньютонова интерполяция)
				double xnewton[] = {0,  1,  2,  3,  4,  5,  6,   7,   8,   9,   10};
		 		double ynewton[] = {0,  1,  2,  3,  4,  5,  6,   7,   8,   9,   10};
				polynomialfit(NP, DEGREE, xnewton, ynewton, coeff);

				//printf("y(x)=%lf*x^3+%lf*x^2+%lf*x\n",coeff[2],coeff[1],coeff[0]);
				//Вывод изображений шаблонов и информации о них 
				if(limit_i<=limit)
				{
				string number_image=render_square_image(temp_patterns,iterration);
				html+="<div><img src='../juliakernel/output/images/"+number_image+".bmp' width='100' height='100'></div>";
				html+="<small>Функция движения<br>";
				if(round(coeff[2])!=0)html+=convert::to_string(round(coeff[2]))+"*x<sup><small>2</small></sup>";
				if(round(coeff[1])!=0)html+="+"+convert::to_string(round(coeff[1]))+"*x";		
				if(round(coeff[0])!=0)html+="+"+convert::to_string(round(coeff[0]))+"";
				int res=coeff[2]*(poly_x^2)+coeff[1]*(poly_x^1)+coeff[0];
				html+="<br>";
				html+="Функция наличия<br>";
				if(round(coeff[2])!=0)html+=convert::to_string(round(coeff[2]))+"*x<sup><small>2</small></sup>";
				if(round(coeff[1])!=0)html+="+"+convert::to_string(round(coeff[1]))+"*x";		
				if(round(coeff[0])!=0)html+="+"+convert::to_string(round(coeff[0]))+"";
				//int res=coeff[2]*(poly_x^2)+coeff[1]*(poly_x^1)+coeff[0];
				html+="<br></small>";
				}
				limit_i++;
				//Вывести результаты
			}
    		}
	//ti = clock() - ti;
        //printf("Time: %f \n", (double)ti/CLOCKS_PER_SEC);
	//Server start
	
	//queue
	//queue not working
	
 	addrlen = sizeof(clientaddr);
        clients[slot] = accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);
        if (clients[slot]<0)perror ("accept() error");
        else
        {
            //if ( fork()==0 )
            //{
                respond(slot,html);
            //}
        }
        while (clients[slot]!=-1) slot = (slot+1)%CONNMAX;
	
	for (int i2=0; i2<CONNMAX; i2++)
	{
        //shutdown(clients[i2],SHUT_RDWR);         //All further send and recieve operations are DISABLED...
        //close(clients[i2]);
        //clients[i2]=-1;
	}	
	//Server end
	
	}
	///Save html output in file for debugging
	//savelog(html);
	return 0;
}
