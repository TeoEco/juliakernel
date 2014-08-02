#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myheader.h"


struct Data {
	int yy,mm,dd;
};

struct tagGoods {
	double price;
	char name[50];
	char *prod;
	int weight;
	struct Data data;
};

union Argb
{
unsigned long color;
unsigned char argb[3];
};


typedef struct tagGoods Goods;

void PutGoods(Goods g)
{
	printf("%s %s %d %g %d %d %d",g.name,g.prod,g.weight,g.price,g.data.yy,g.data.mm,g.data.dd);
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void CopyGoods(Goods *d,Goods *s)
{
*d=*s;//Копируем побитово одну структуру в другую кроме динамически выделенной памяти
d->prod=NULL;
d->prod=(char *)malloc(strlen(s->prod)+1);
strcpy(d->prod,s->prod);
}

void GetGoods(Goods *pgoods)
{
	Goods tmp;
	char buf[255];

	printf("Input YYYY MM DD:");
	scanf("%d %d %d",&tmp.data.yy,&tmp.data.mm,&tmp.data.dd);
	clean_stdin();
	printf("Input name:");
	//gets(tmp.name);
	fgets(tmp.name, 255, stdin);


	printf("Input price weight:");
	scanf("%lf %d",&tmp.price,&tmp.weight);
	clean_stdin();
	
	printf("Input prod:");
	//gets(buf);
	fgets(buf, 255, stdin);
		
	tmp.prod= (char *) malloc(strlen(buf)+1);//Выделение памяти
	strcpy(tmp.prod,buf);
	
	*pgoods=tmp;
}
void main()
{
	Goods g , g2 , *pg=&g;//Указатели через стрелки
	
	printf("size=%lu",sizeof(g));
	
	g.price=7.0;
	g.data.yy=2011;
	pg->price=5.0;
	pg->data.mm=5;

	GetGoods(&g);
	CopyGoods(&g2,&g);
	PutGoods(g2);		

	{
	union Argb c1;
	c1.argb[0]=100;
	c1.argb[1]=100;
	c1.argb[2]=100;
	printf("color=%lu",c1.color);	
	}

}
