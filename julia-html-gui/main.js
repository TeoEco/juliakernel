//Play video from images list
function video(name,count)
{
	for(i=1;i<=count;i++)
	{
	document.getElementById('video').innerHTML='<img src="images/'+name+'-'+i+'.bmp">';
	sleep(100);	
	}
}
