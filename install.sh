##Install script Artificail Intelligence packages
apt-get  update
#For make screens
apt-get  -y install libcairo2-dev
apt-get  -y build-dep cairo
#For Newton interpolation
apt-get  -y install libgsl0ldbl libgsl0-dev
#For compile and linking application
apt-get -y install g++ gcc
apt-get -y install build-essential cmake pkg-config
#For help with compile
apt-get  -y install make
#For activation Linux  - window
apt-get  -y install wmctrl
#For control mouse and keyboard
apt-get  -y install xdotool
#For Nintendo (Dendy) games
apt-get -y  install fceux
#For work with sound
apt-get  -y install libopenal-dev
#For antialiasing fonts 
#apt-get install libfreetype6-dev:i386

#For Qt-Webkit
apt-get  -y install libgstreamer1.0-dev
apt-get  -y install libgstreamer0.10-dev
apt-get  -y install libgstreamer-plugins-base1.0-dev
apt-get  -y install libgstreamer-plugins-base0.10-dev
apt-get  -y install libxslt1-dev

