
/*Комментарии к программе*/
/*Управление*/
//Управление клавишами с помощью xdtool 
/*

//omp_set_dynamic(10);
//omp_set_num_threads(10);


printf("Max_Threads = %d\n", omp_get_max_threads());
printf("Доступно процессоров для параллельного выполнения = %d\n", omp_get_num_procs());
printf("Option.Dynamic = %d\n",omp_get_dynamic());
printf("Option.parallel In parallel = %d\n",omp_get_nested());

xdotool mousemove --sync 1000 10
xdotool mousemove --sync 1000 10
xdotool click 3
xdotool key ctrl+c
Скриншот
       if ((ptr = popen(cmd2.c_str(), "r")) != NULL) while (fgets(buf, BUFSIZ, ptr) != NULL)(void) printf("%s", buf);(void) pclose(ptr);


Создание скриншота
//cmd = "import -window 'FCEUX 2.2.1' screen.bmp";
//exec(cmd);	

//Чтение bmp-файла
   	 std::string file_name("screen.bmp");
  	 bitmap_image image(file_name);
  	 if (!image)
  	 {
        	printf("test01() - Error - Failed to open '%s'\n",file_name.c_str());
        	return 0;
  	 }	
		int dim=100;
		  for (unsigned int x = 0; x < dim; ++x)
		   {
		      for (unsigned int y = 0; y < dim; ++y)
		      {
			 rgb_store col = jet_colormap[(x + y) % dim];
			 image.set_pixel(x,y,col.red,col.green,col.blue);
		      }
		   }
Работа с режимами

	
string mode=argv[1];
 	if(argc!=2) {
 	   printf("Вы забыли ввести режим.\n");
 	   exit(1);
 	}
	int disp;
  	//if(argc==3 && !strcmp(argv[2], "display")) disp = 1;
 	// else disp = 0;
	
Таймер

    timer=clock();
    cout<<clock()-timer<<endl;

Запись видео с рабочего стола из консоли
	ffmpeg -f x11grab -r 25 -s 1024x768 -i :0.0+100,200 -f alsa -ac 2 -i pulse output.



/*
//Функция уменьшения изображения
std::vector<unsigned char> bicubicresize(const std::vector<unsigned char>& in, std::size_t src_width,
    std::size_t src_height, std::size_t dest_width, std::size_t dest_height)
{
    std::vector<unsigned char> out(dest_width * dest_height * 3);

    const float tx = float(src_width) / dest_width;
    const float ty = float(src_height) / dest_height;
    const int components = 3;
    const int bytes_per_row = src_width * components;

    const int components2 = components;
    const int bytes_per_row2 = dest_width * components;

    int a, b, c, d, index;
    unsigned char Ca, Cb, Cc;
    unsigned char C[5];
    unsigned char d0, d2, d3, a0, a1, a2, a3;

    for (int i = 0; i < dest_height; ++i)
    {
        for (int j = 0; j < dest_width; ++j)
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
                    d0 = in[(y - 1 + jj) * bytes_per_row + (x - 1) * components + k] - in[(y - 1 + jj) * bytes_per_row + (x) * components + k];
                    d2 = in[(y - 1 + jj) * bytes_per_row + (x + 1) * components + k] - in[(y - 1 + jj) * bytes_per_row + (x) * components + k];
                    d3 = in[(y - 1 + jj) * bytes_per_row + (x + 2) * components + k] - in[(y - 1 + jj) * bytes_per_row + (x) * components + k];
                    a0 = in[(y - 1 + jj) * bytes_per_row + (x) * components + k];
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
                    out[i * bytes_per_row2 + j * components2 + k] = Cc;
                }
            }
        }
    }

    return out;   
}

/*
    string znach;
    int y,x,val;
    for (iter1=pixels_image.begin(); iter1!=pixels_image.end(); iter1++) {
    	x=iter1->first;
		for (iter2=pixels_image[x].begin(); iter2!=pixels_image[x].end(); iter2++) {
		y=iter2->first;
				znach=pixels_image[x][y];
				//Значит в znach нужны все-возможные строки с лимитом длины 600 ,то есть умножить множество на 600 ещё
				//И змейка имеет минусы - если внутри полости - но не в этом случае
				//Квадрат
				
 				 val=pixels_map[znach].size();
				 pixels_map[znach][val][1]=i;
				 pixels_map[znach][val][2]=x;
 				 pixels_map[znach][val][3]=y;

		}
    }
	

	for(int zi=0;zi<10000000000000;zi++)
	{
 	pixels_map[znach][zi][1]=1;
	}


Foreach pixels_map 
странный город  днем город - это множество вида
с 
ст 
стр
стра

с**a

Да ,можно начать с азов - потом соседние(лучше по кругу) - потом 

Задача - выделить области со всего изображения и их приплюсовать к массиву с [i][xx][yy] ,для этого относительные пути в 
строке и лимит
Как втой программе ,но с усложнением ***
*/
    //Создание массива разностей
//Можно отказаться от std




			//pixels_image[x][y]="r"+convert::to_string(redi)+"g"+convert::to_string(greeni)+"b"+convert::to_string(bluei);


			//Сохранение оригинального скриншота
			//datapng[y * stride + x * 4 + 0] = blue ;
			//datapng[y * stride + x * 4 + 1] = green; 
			//datapng[y * stride + x * 4 + 2] = red;   /* yes, in this order */
 			//Конвертация в char или сохранение в массив
			//snprintf(red, sizeof(red), "%d", intvar);

/*
Объявления массива

std::map<std::string, int> mymap = {{"one", 1}, {"two", 2}, {"three", 3}};

std::pair<int, std::string> map_data[] = {
    std::make_pair(1, "a"),
    std::make_pair(2, "b"),
    std::make_pair(3, "c")
};


*/

			//В принципе тут можно упростить если передавать к качестве ключей пиксели
			/*
			 for(size_t i3 = 0; i3 < dim_i; ++i3)
			  {
			    	A[i][0]=A[i][0]+abs(minx);
			  		A[i][1]=A[i][1]+abs(miny);
			  		if(i==A[i3][0] and i2==)
			  		{
			  			
			  		}
			  }
			  */




/*

polynomialfit(NP, DEGREE, xnewton, ynewton, coeff);
 	 for(int i=0; i < DEGREE; i++) {
  	  printf("%lf\n", coeff[i]);
 	 }
$iviv=1;
$limit=200;
foreach($structurs as $k=>$v)
{
if($iviv>$limit)break;
	$flag=false;
	$cvet=0;
		foreach($v['koor'] as $k2=>$v2)
		{
			if($v2['i']==$i)
			{
			$cvet++;
			$flag=true;
			$cvet=$k2;
			}
		}
	
	if($flag===true)
	{
	if($iviv>$limit)break;
		$limit3=1;
			$buff1='';
			//Вывод массива всех положений фрагментов
			
			foreach($v['koor'] as $k2=>$v2)
			{
			$limit2=1;
				//Вывод массива смещений для одного из фрагментов
				if(count($v2['smes'])>0)
				{
					$buff1.='<br>';
					foreach($v2['smes'] as $k30=>$v30)
					{
					$limit2++;
					$limit3++;
					if($v30[2]==$i)$buff1.='x:'.$v30[1].'y:'.$v30[0].'<br>';
					if($limit2>3)break;
					}
				}
			if($limit3>10)break;//Ограничитель на количество показов
			}
			
				foreach($v['smes'] as $k30=>$v30)
				{
				if($v30[2]==$i)$buff1.='<small>x='.$v30[1].';y='.$v30[0].';</small>';
				}
			echo '<br><small>Номер:</small>';
			echo '<small><small><font color="">'.$k.'</font></small></small><br>';
			echo '<small>Cмещение:</small>';
			echo '<small><font color="">'.$buff1.'</font></small>';

			//if($k==10 and $i==5)print_r($structurs[$k]['smesfunction']);
			if(strlen($v['smesfunction'][$i]['x'])>0)
			{
			echo '<br><small>Функция смещения по x:</small><br>';
			echo '<small><font color="blue">'.$v['smesfunction'][$i]['x'].'</font></small>';
			}
			if(strlen($v['smesfunction'][$i]['y'])>0)
			{
			echo '<br><small>Функция смещения по y:</small><br>';
			echo '<small><font color="blue">'.$v['smesfunction'][$i]['y'].'</font></small>';
			}


				echo '<br><small>Количество:'.count($v['koor']).'</small><br>';
			$data=array();
			$sum1=0;$sum2=0;
			foreach($v['pixels'] as $k2=>$v2)
			{
			//$sum1=$sum1+;
			//$sum2=$sum2+;
			$data[]=array($v2[1],$v2[2]);
			}
			  bcscale( 10 );
			  // Start a regression class with a maximum of 4rd degree polynomial.
			  $polynomialRegression = new PolynomialRegression( 4 );
			  foreach ( $data as $dataPoint )$polynomialRegression->addData( $dataPoint[ 0 ], $dataPoint[ 1 ] );
			  $coefficients = $polynomialRegression->getCoefficients();
			  $functionText='';
			  foreach ( $coefficients as $power => $coefficient )
			  {
				if ( $power > 0 )
				if($coefficient!=0)
				{
				  if($coefficient>0 and $power>1)$functionText .= "+";
				$functionText .= round( $coefficient, 2 );

					if ( $power > 0 )
					{
					  $functionText .= 'x';
					  if ( $power > 1 )
						$functionText .= "^" . $power;
					}
				}
			  }
			  if(strlen($functionText)>0)
			  {
			 
			  }
			  else
			  {
			   $functionText='0';
			  };
			  echo '<small>Функции прямых фрагмента</small>:<br>';
			  echo "<small><font color='blue'>f(x)=";
			  echo  $functionText;
			  echo '</font></small>';
			  				render_square($v['pixels']);//Вывод картинки

			  	
		$iviv++;
	}
}
//if($i==3)exit;
$diap=0;
foreach($svyaz_array as $prom=>$vn)
{					
	foreach($vn as $znach=>$v)
	{
		foreach ($v as $k2=>$v2)
		{	
			$k3=$k2-1;
			$p1=$v[$k3][0];
			$p2=$v[$k2][0];
			if($p1==$p2)
			{
				if(count($diapozon[$diap])==0)
				{
				$diapozon[$diap]['nach']=$k2;
				$diapozon[$diap]['znach']=$znach;
				$diapozon[$diap]['prom']=$prom;
				$diapozon[$diap]['nach2']=$v[$k2][1];
				}
			}
			else
			{
				$diapozon[$diap]['kone']=$k2;
				$diapozon[$diap]['kone2']=$v[$k2][1];
				$diap++;
			}
			
		}
	}
}
$zak_p=array();
if(count($diapozon)>0)
{
	foreach($diapozon as $k=>$v)
	{
		if($i==1)
			{
				if(strlen($v['prom'])>0 and $v['prom']!=0 and strlen($v['znach'])>0)
				{
					$zak_p[]=array(
					1=>array(array(1=>'x%'.$v['prom'],2=>'==',3=>1),array(1=>'y',2=>'<',3=>$v['kone2']),array(1=>'y',2=>'>',3=>$v['nach2'])),
					2=>array(array(1=>'vi',2=>$v['znach']))
					);
				}
			}
	}
}
//print_r($svyaz_array);
//Расширение закономерностей или сохранение в виде кода

echo '<br><font color=grey>Пример модели в виде закономерностей:<br>
<small>(картинка частично переведенная в PHP-код)</small>
</font>
';
//Код программы
/*
$structurs=array();
$structurs[1]=array(
'koor'=>array(
array('x'=>1,'y'=>1,'i'=>'1'),
array('x'=>1,'y'=>1,'i'=>'3')
),
'pixels'=>1
);
$structurs[2]=array(
'koor'=>array(
array('x'=>1,'y'=>1,'i'=>'2'),
array('x'=>1,'y'=>1,'i'=>'4')
),
'pixels'=>2
);

//Определение закономерностей

//Много из-за smes_toch и x y



$obratk=1;
if($obratk==1)
{
	foreach($zak_p as $k=>$v)
	{
		foreach($zak_p as $k2=>$v2)
		{
			if($v[2]==$v2[2] and $v[3]==$v2[3])
			{
			
			}
		}
	}
}
		$kod='';
		$flag=0;
	foreach($zak_p as $k=>$v)
	{
		$kodand='';
		foreach($v[1] as $k2=>$v2)
		{
			if(strlen($v2[1])>0 and strlen($v2[3])>0)
			{
			$flag++;
			$kodand.=' and ($'.$v2[1].$v2[2].$v2[3].')';
			}
		}
		$kodand=substr($kodand,5);
				if($flag==1)
				{
				$kodand=substr($kodand,1);
				$kodand=substr($kodand,0,-1);
				}
		$flag=0;
		$vix1='';
		$vix2='';
		foreach($v[2] as $k2=>$v2){$vix1.='$'.$v2[1].'="'.$v2[2].'";'."\n";};
		foreach($v[3] as $k2=>$v2){$vix2.='$'.$v2[1].'="'.$v2[2].'";'."\n";};

		$kod.='
		if('.$kodand.')
		{
		'.$vix1.'}';
		if(strlen($vix2)>0)
		{
		$kod.='
		else
		{
		'.$vix2.'}';
		}
	}

echo '
<br><textarea style="height:200px;">';
echo htmlspecialchars($kod);
echo '</textarea>';
//Обратный реверсинг
$a=-10;
echo '</td>';
}
echo '<td style="width:100px;" valign="top"></td>';
echo '<td valign="top"><!--red--><font color="blue"><small>Вычисленное будущее состояние системы с появлением и исчезновением:</small></font>';
				//Возникновение и исчезновение
				foreach($structurs as $k=>$v)
				{
						$mass=array();
						foreach($structurs[$k]['po'] as $k2=>$v2)
						{
						$mass[]=$k2;
						}
						sort($mass);
									$data=array();
									foreach($mass as $k2=>$v2)
									{
									//$sum1=$sum1+;
									//$sum2=$sum2+;
									$data[]=array($k2,$v2);
									}
								//	print_r($data);
									  bcscale( 10 );
									  // Start a regression class with a maximum of 4rd degree polynomial.
									  $polynomialRegression = new PolynomialRegression( 4 );
									  foreach ( $data as $dataPoint )$polynomialRegression->addData( $dataPoint[ 0 ], $dataPoint[ 1 ] );
									  $coefficients = $polynomialRegression->getCoefficients();
									  $functionText='';
									  foreach ( $coefficients as $power => $coefficient )
									  {
										if ( $power > 0 )
										if($coefficient!=0)
										{
										  if($coefficient>0 and $power>1)$functionText .= "+";
										$functionText .= round( $coefficient, 2 );
										if ( $power > 0 ){$functionText .= '*$x';if ( $power > 1 )$functionText .= "^" . $power;}}}
									  if(strlen($functionText)>0)
									  {
									  }
									  else
									  {
									   $functionText='0';
									  };
					$smes2[$k]=$functionText;
									
				}	
		for($sch=5;$sch<9;$sch++){
		$array=array();
		//Для всех фрагментов в кажом случае нужно понять появляются они или нет
		
		//По сути это такие же функции как и прямые.В данном случае данные это массив для фрагмента появления.
		//Но функции не обладают "стрессоустойчивостью".
		//Если для каждого фрагмента сделать массив появления ,то для через 2 он будет 2,4,6,7,10,12,14 y=$x*2;
		//Если я наоброт разделю счетчик на два ,и если x будет целым числом,то сработать
		
				//Рендер
			
				foreach($budus as $k=>$v)
				{
				$fkag=false;
				$cif=substr($smes2[$k],0,strpos($smes2[$k],'*'));
				$flag=false;
				if(is_numeric($cif))
				{
				$res=$sch/$cif;
				//if($k==24)var_dump($res);
					if(is_int($res))
					{
					$flag=true;
					}
				}
				//$smes2[$k] из 3*$x сделать $x/3
						if($flag===true)
						{
								$x=$sch;$x1='';$y1='';
								if(strlen($v['fx'])>0)eval('$x1='.$v['fx'].';');
								if(strlen($v['fy'])>0)eval('$y1='.$v['fy'].';');
								if($k==14)
								{
								//var_dump($x1);var_dump($y1);
								}
								if(strlen($x1)==0){$x1=$v['x'];}
								else
								{
								$x1=$v['x2']+$x1;
								};
								if(strlen($y1)==0){$y1=$v['y'];}
								else
								{
								$y1=$v['y2']+$y1;
								};
								$x1=(string)round($x1);$y1=(string)round($y1);
								foreach($v['pixels'] as $k2=>$v2)
								{
								$v2=array($v[1]+$y1,$v2[0]+$x1,$v2[2],$k);
								$array[]=$v2;
								}
						}
				}
		render_square($array,1);
		echo '<br>';
		}
	
echo '<font color="blue">Функции смещения фрагментов:</font>';
foreach($smes as $k=>$v)
{
	if(strlen($v)>0)
	{
				echo "<br><!--Функция №".$k." :--><small><font color='blue'>f(x)=";
				echo  $v.';';
				echo '</font></small>';
	}
}

echo '<br><br><font color="red">Функции появления и исчезновения фрагментов:</font>';
foreach($smes2 as $k=>$v)
{
	if(strlen($v)>1)
	{
				echo "<br><!--Функция №".$k." :--><small><font color='red'>f(x)=";
				echo  $v.';';
				echo '</font></small>';
	}
}
echo '</td>';
echo '
</tr>
<td  colspan="5"style="text-align:center;"><font color="grey">Общая программа всех картинок:</font></td></tr>
</table>';
*/













/*




//$search_patterns[$i][$znach][$x][$y][]=array($prom1,$prom2);
foreach($search_patterns as $k=>$v)
{
//$k=$i;-Номер первого рисунка
	foreach($v as $znach=>$v2)
	{
	//$znach=$znach; -Цвет первого совпадения
		foreach($v2 as $k3=>$v3)
		{
		//$k3=$x; -Координата по горизонатали совпадения
			foreach($v3 as $k4=>$v4)
			{
			//$k4=$y; -Координата по вертикали совпадения
					foreach($search_patterns as $k6=>$v6)
					{
					//$k6=$i2;
						//if($k==$i or $k6==$i)//Стопор для обработки только текущего кадра 
						//echo $i.'|'.$k.'|'.$k6.'|'.$znach.'<br>';
						//if(($i-$k)<=1 and (($i-$k6)<=1))//Cтопор для обработки только соседних кадров
						if($k6==$i and  (($i-$k)<=1))
						{
							foreach($v6 as $znach2=>$v7)
							{
							//$znach2=$znach2;
								if($znach==$znach2)
								{
								foreach($v7 as $k8=>$v8)
								{
								//$k8=$x2;
									foreach($v8 as $k9=>$v9)
									{
										$pixels=array();
										//Код ищет совпадения областей между рисунками
										//$k9=$y2;
										foreach($v4 as $k5=>$v5)
										{
										//$k5 - список пикселей;
											foreach($v9 as $k10=>$v10)
											{
												if($v5[0]==$v10[0] and $v5[1]==$v10[1] and $v5[2]==$v10[2])//
												{
													if($i==1)
													{
													//echo 'Счетчик картинок:Первый - '.$k.' Второй - '.$k6.'<br>';
													//echo 'Значение цвета1:'.$znach.',Значение цвета2:'.$znach2.'<br>';
													//echo 'Абсолютные вторые координаты x='.$k8.'<br>Асбоолютные вторые координаты y='.$k9.'<br>';
													//echo 'относительные координаты по x='.$v10[0].'|относительные координаты по y='.$v10[1].'<br>';
													//echo '<br>';
													}
												//$kv=sqrt($v10[0]^2+$v10[1]^2);
												$pixels[]=array($v10[0],$v10[1],$v10[2]);
												}
											}
										}
											//Тяжелая конструкция начало
											if(count($pixels)>0 )
											{
											//print_r($pixels);
											//print_r($v4);
											//print_r($v9);
											//echo '<br>';
														//Нужно записывать к пикселям и основной пиксель
														$array=array();
														//Не надо добавлять .Так как в массиве уже есть 0,0 точки
														$array['pixels']=koor1($pixels);//Приведение к общим координатам
														$x_otn=$k8+$smes_toch[0];//Координаты крайней правой точки
														$y_otn=$k9+$smes_toch[1];//Координаты крайней левой точки
														$array2=$array['pixels'];
														addstruct();//Добавление прямых из фрагмента
														$array2=array();
													//	print_r($structurs);
													//	exit;
														$zap_array=array('x'=>$k8,'y'=>$k9,'i'=>$i,'smes_toch'=>$smes_toch);
														$array['koor'][]=$zap_array;
														$array['po'][$i]=1;
														$flag2=false;
															foreach($structurs as $k_2=>$v_2)
															{
																Очистка от повторяющихся структур
																if($v_2['pixels']==$array['pixels'])
																{
																$new_arr=$zap_array;
																$flag_povt=0;
																foreach($v_2['koor'] as $k2_2=>$v2_2)
																{
																	if($new_arr==$v2_2)$flag_povt=1;
																}
																if($flag_povt!=1)
																{
																$structurs[$k_2]['koor'][]=$new_arr;
																$structurs[$k_2]['po'][$i]=1;
																}
																$flag2=true;
																}
															}
															if($flag2===false)
															{
															$structurs[]=$array;
															}

											}
									}
								}
								}
							}
						}
					}
			}
		}
	}
}

/*
    //Создание массива структур
    //Указатели для перебора  search_patterns
	map< int, map< int,  map< int,  map< int,  map< int,  map< int, int > > > > > >  ::const_iterator iter1_1;
	map< int, map< int,  map< int,  map< int,  map< int, int > > > > >  ::const_iterator iter1_2;
	map< int, map< int,  map< int,  map< int, int > > > >  ::const_iterator iter1_3;
	map< int, map< int,  map< int, int > > >  ::const_iterator iter1_4;
	map< int, map< int, int  > >  ::const_iterator iter1_5;
	map< int, int>  ::const_iterator iter1_6;
    //Указатели для перебора  search_patterns
	map< int, map< int,  map< int,  map< int,  map< int,  map< int, int > > > > > >  ::const_iterator iter2_1;
	map< int, map< int,  map< int,  map< int,  map< int, int > > > > >  ::const_iterator iter2_2;
	map< int, map< int,  map< int,  map< int, int > > > >  ::const_iterator iter2_3;
	map< int, map< int,  map< int, int > > >  ::const_iterator iter2_4;
	map< int, map< int, int  > >  ::const_iterator iter2_5;
	map< int, int>  ::const_iterator iter2_6;

    //Большой массив
    for (iter1_1=search_patterns.begin(); iter1_1 != search_patterns.end(); iter1_1++) {
    	int i_p=iter1_1->first;
		for (iter1_2=search_patterns[i_p].begin(); iter1_2 != search_patterns[i_p].end(); iter1_2++) {
		int znach_p=iter1_2->first;
			for (iter1_3=search_patterns[i_p][znach_p].begin(); iter1_3 != search_patterns[i_p][znach_p].end(); iter1_3++) {
			int x_p=iter1_3->first;
				for (iter1_4=search_patterns[i_p][znach_p][x_p].begin(); iter1_4 != search_patterns[i_p][znach_p][x_p].end(); iter1_4++) {
				int y_p=iter1_4->first;

				
					
						//Внутренний перебор


						for (iter2_1=search_patterns.begin(); iter2_1 != search_patterns.end(); iter2_1++) {
						int i2_p=iter2_1->first;

							//if(i2_p==i or k6==i_p)//Стопор для обработки только текущего кадра 
							if(i2_p==i and  ((i-i_p)<=1))
							{

							for (iter2_2=search_patterns[i2_p].begin(); iter2_2 != search_patterns[i2_p].end(); iter2_2++) {
							int znach2_p=iter2_2->first;
								if(znach_p==znach2_p)
								{
								for (iter2_3=search_patterns[i2_p][znach2_p].begin(); iter2_3 != search_patterns[i2_p][znach2_p].end(); iter2_3++) {
								int x2_p=iter2_3->first;
									for (iter2_4=search_patterns[i2_p][znach2_p][x2_p].begin(); iter2_4 != search_patterns[i2_p][znach2_p][x2_p].end(); iter2_4++) {
									int y2_p=iter2_4->first;

i_cout++;

					pixels.clear();
					for (iter1_5=search_patterns[i_p][znach_p][x_p][y_p].begin(); iter1_5 != search_patterns[i_p][znach_p][x_p][y_p].end(); iter1_5++) {
					int itt1=iter1_5->first;


										for (iter2_5=search_patterns[i2_p][znach2_p][x2_p][y2_p].begin(); iter2_5 != search_patterns[i2_p][znach2_p][x2_p][y2_p].end(); iter2_5++) {
					int itt2=iter2_5->first;

					if(search_patterns[i_p][znach_p][x_p][y_p][itt1][0]==search_patterns[i_p][znach_p][x_p][y_p][itt2][0] and search_patterns[i_p][znach_p][x_p][y_p][itt1][1]==search_patterns[i_p][znach_p][x_p][y_p][itt2][1])
					{

//$kv=sqrt($v10[0]^2+$v10[1]^2);
//$pixels[]=array($v10[0],$v10[1],$v10[2]);
//Можно перейти на обычный массив
pixels[0][0]=search_patterns[i_p][znach_p][x_p][y_p][itt2][0];
pixels[0][1]=search_patterns[i_p][znach_p][x_p][y_p][itt2][1];
pixels[0][2]=search_patterns[i_p][znach_p][x_p][y_p][itt2][2];
					}

				      }

				      }
					
					if(pixels.size()>0)
					{

					array.clear();
					//array['pixels']=koor1(pixels);//Приведение к общим координатам
					}
										/*
										cout << "Равенство координат - "  
										<< "i1="<< i_p 
										<< "znach1="<< znach_p 
										<< "x1="<< x_p 
										<< "y1="<< y_p 
										<< "itt1="<< itt1 
										<< "mass=" << search_patterns[i_p][znach_p][x_p][y_p][itt1] << 
										endl;
										cout << "Равенство координат - "  
										<< "i2="<< i2_p 
										<< "znach2="<< znach2_p 
										<< "x2="<< x2_p 
										<< "y2="<< y2_p 
										<< "itt2="<< itt2 
										<< "mass2=" << search_patterns[i2_p][znach2_p][x2_p][y2_p][itt2] << 
										endl;
										

									}
								}
								}
							}
							}
						}			 
							
							 
				}
	    		}
    		}
	}



*/
/*
	map< int, map< int, int  > >  ::const_iterator iter_structurs_1;
	map< int, map< int, int  > >  ::const_iterator iter_structurs_2;
	map< int, map< int, int  > >  ::const_iterator iter_structurs_3;

    //Добавление смещений к структурам
    for (iter_structurs_1=structurs.begin(); iter_structurs_1 != structurs.end(); iter_structurs_1++) {
    int k=iter_structurs_1->first;
    	for (iter_structurs_2=structurs[koor].begin(); iter_structurs_2 != structurs[koor].end(); iter_structurs_2++) {
    	int k2=iter_structurs_2->first;

    		for (iter_structurs_3=structurs[koor].begin(); iter_structurs_3 != structurs[koor].end(); iter_structurs_3++) {
    		int k3=iter_structurs_3->first;
			//Сравнение координат только соседних рисунков  и только в одну сторону
			if(structurs[koor][k2]==i and (structurs[koor][k2]['i']-structurs[koor][k3]['i'])==1)
			{
			int smes1=structurs[koor][k2]['x']-structurs[koor][k3]['x'];
			int smes2=structurs[koor][k2]['y']-structurs[koor][k3]['y'];
			structurs[k]['smes'][i]={smes1,smes2};
						
						//Можно добавить сложные смещения
						
						
						//echo '<br>
						//<h1>Блок информации</h1>
						//абсолютный x первого цикла='.($v2['x']).'<br>
						//абсолютный y первого цикла='.($v2['y']).'<br>
						//абсолютный x2 второго цикла='.($v3['x']).'<br> 
						//абсолютный y2 втрого цикла='.($v3['y']).'<br>';
						//echo 
						//'Получившаяся разность координат по x:'.($v2['x']-$v3['x']).'<br>';
						//echo 
						//'Получившаяся разность координат по y:'.($v2['y']-$v3['y']).'<br>';
			}
    		
		}
   	 }
	
    }
*/
/*
    //Определение функций смещений
    for (iter_structurs_1=structurs.begin(); iter_structurs_1 != structurs.end(); iter_structurs_1++) {
    int k=iter_structurs_1->first;
    	if(structurs[k]['smes'].size()==0 or k==24)
	{
	int sag=1;
		int i_for_array=0;
		//Сложение разности между соседними x	
		const int iop=structurs[k]['smes'].size();
		double xnewton[iop];
		double ynewton[iop];
		for(iter_structurs_1=structurs[k]['smes'].begin(); iter_structurs_1 != structurs[k]['smes'].end(); iter_structurs_1++)
		{
		int v20=;
			int sum=sum+v20;
			data[i_for_array]={sag,sum};
	
			xnewton[i_for_array]=i_for_array;
			ynewton[i_for_array]=sum;
			i_for_array++;
			sag++;
			
		}
		//double xnewton[] = {0,  1,  2,  3,  4,  5,  6,   7,   8,   9,   10};
 		//double ynewton[] = {0,  1,  2,  3,  4,  5,  6,   7,   8,   9,   10};
		polynomialfit(NP, DEGREE, xnewton, ynewton, coeff);
		 	 for(int i=0; i < DEGREE; i++) {
		  	  printf("%lf\n", coeff[i]);
		 	 }
		//Ньютонова интерполяция вызов
		//Ньютонова интерполяция вывод
	
/*
map< int, map< int, int  > >  ::const_iterator iter1_1;
map< int, int>  ::const_iterator iter1_2;

    for (iter1_1=structurs.begin(); iter1_1 != structurs.end(); iter1_1++) {
    	string string_pattern=iter1_1->first;
		for (iter1_2=structurs[string_pattern].begin(); iter1_2 != structurs[string_pattern].end(); iter1_2++) {
		int znach_p=iter1_2->first;
		}
   }
*/		
	}
    }
/**

*/
/*
int hash(std::string string)
{

size_t precision = 2; //change the precision with this
size_t hash(const char* str)
{
   return (*(size_t*)str)>> precision;
}
std::string str = "Meet the new boss...";
    std::hash<std::string> hash_fn;
    size_t str_hash = hash_fn(str);
 
    std::cout << str_hash << '\n';
string.c_str(); 

int key=5;
return key;
}
			//Проверка если объект найден
				int iter12=structurs[object][-1][0];
				iter12++;
				structurs[object][iter12][0]=i;
				structurs[object][iter12][1]=MINX;//Запись x
				structurs[object][iter12][2]=MINY;//Запись y

				//structurs[object][iter12][3]=dx;
				//structurs[fobject][iter12][4]=dy;
					
				structurs[object][-1][0]=iter12;
*///printf("Секунд с момента начальной загрузки: %lu минут\n", info.uptime/60);
	//printf("Объем раздела подкачки: %lu (%lu MB)\n", info.totalswap, info.totalswap/(1024*1024));

/*
using namespace std;

void main()
{
    //  Array 3 Dimensions
    int x = 4, y = 5, z = 6;

    //  Array Iterators
    int i, j, k;

    //  Allocate 3D Array
    int ***array3D = new int**[x];

    for(i = 0; i < x; i++)
    {
        array3D[i] = new int*[y];

        for(j = 0; j < y; j++)
        {
            array3D[i][j] = new int[z];
        }
    }

    //  Access array elements
    for(i = 0; i < x; i++)
    {
        cout << i << endl;

        for(j = 0; j < y; j++)
        {
            cout << endl;

            for(k = 0; k < z; k++)
            {
                array3D[i][j][k] = (i * y * z) + (j * z) + k;
                cout << '\t' << array3D[i][j][k];
            }
        }

        cout << endl << endl;
//printf("y(x)=%lf*x^3+%lf*x^2+%lf*x\n",coeff[2],coeff[1],coeff[0]);
    }

    //  Deallocate 3D array
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < y; j++)
        {
            delete[] array3D[i][j];
        }

        delete[] array3D[i];
    }
    delete[] array3D;
}
/*
                if ( strncmp(reqline[1], "/\0", 2)==0 )
                    reqline[1] = "/index.html";        //Because if no file is specified, index.html will be opened by default (like it happens in APACHE...
                strcpy(path, ROOT);
                strcpy(&path[strlen(ROOT)], reqline[1]);
                printf("file: %s\n", path);

                if ( (fd=open(path, O_RDONLY))!=-1 )    //FILE FOUND
                {
                    send(clients[n], "HTTP/1.0 200 OK\n\n", 17, 0);
                    while ( (bytes_read=read(fd, data_to_send, BYTES))>0 )
                        write (clients[n], data_to_send, bytes_read);
                }
                else    write(clients[n], "HTTP/1.0 404 Not Found\n", 23); //FILE NOT FOUND
*/ 
	//QLabel hello(html.c_str());
	//hello.setWindowTitle("Мозг на C++");
	//hello.resize(1200,1000);
	//hello.show();
	//Установка кодировки вывода HTML - кода в QT-окне
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); 
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));




