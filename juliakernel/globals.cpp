/*
Глобальные массивы и перепменные программы
*/
//Название заголовка окна с игрой
const string windowname="FCEUX 2.2.1";

//Массив с пикселями окна с игрой
char in[300][300][3];

//Массив с найденными закономерностями в пикселях


///Уменьшение изображения - Resize image array
const int nheight=10;
const int nwidth=10;

//Массив с пикселями картинки
int pixels_image[nwidth][nheight][3];

//Таймер для программиста - для имерения времени выполнения участка кода
clock_t  ti;

///Ньютонова интерполяция - данные 
#define NP 11

// double xnewton[] = {0,  1,  2,  3,  4,  5,  6,   7,   8,   9,   10};
// double ynewton[] = {0,  1,  2,  3,  4,  5,  6,   7,   8,   9,   10};

#define DEGREE 3

double coeff[DEGREE];

int iterration=0;
//Счетчик выводимых изобржений
int count_images=0;

//Структура с шаблонами объектов
struct pattern
{
public:
	char pattern[50];
	unsigned int i; 
	unsigned int x; 
	unsigned int y; 
};

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
//Лимит вывода изображений
int limit=3;
