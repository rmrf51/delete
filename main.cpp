#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <complex>
#include <cmath>
#include "map.h" //подключили код с картой
#include "view.h" //подключили код с видом камеры

//#include <stdio.h>
//#include <unistd.h>
// #include "ImGui/"
// #include "ImGui/imgui.cpp"
// #include "ImGui/imgui_draw.cpp"
// #include "ImGui/imgui-SFML.cpp"
// #include "ImGui/imgui_demo.cpp"

// #include "ImGui/imgui.h"
// #include "ImGui/imgui-sfml.h"

// #include <SFML/Graphics/RenderWindow.hpp>
// #include <SFML/System/Clock.hpp>
// #include <SFML/Window/Event.hpp>

using namespace sf;

/*
sf::Sprite boss() { //sf::Image img) {
    const int WW = 286;
    const int HH = 113;
    Image bossimg;//объект изображения
	bossimg.loadFromFile("images/boss.png");//загружаем файл
    //sf::Image bossimg = img;
    sf::Sprite bosssprite;//создаем объект Sprite(спрайт)

    const int delb = 6;
    const int arrb[9] = {1, 1, 1, 1, 9, 1, 1, 1, 1};

    sf::Uint8 *pixelsb = new sf::Uint8[WW*HH*4];
    const sf::Uint8 *pixels1b = new sf::Uint8[WW*HH*4];

	sf::Texture bosstex;//создаем объект Texture (текстура)
	bosstex.loadFromImage(bossimg);//передаем в него объект Image (изображения)

    pixels1b = bossimg.getPixelsPtr();

    for(int i = 0; i < WW*HH*4; i += 1) {
        pixelsb[i] = pixels1b[i];
    }

    for(int i = 0; i < WW*HH*4; i += 1) {

        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;
        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;
        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;

    }

    bosstex.update(pixelsb);
    bosssprite.setTexture(bosstex);
 

	//bosssprite.setTexture(bosstex);//передаём в него объект Texture (текстуры)
    bosssprite.setTextureRect(IntRect(0,0,286,113));
	bosssprite.setPosition(500, 500);//задаем начальные координаты появления спрайта 

    return bosssprite;
    }

*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    view.reset(sf::FloatRect(0, 0, 800, 600));//размер "вида" камеры при создании объекта вида камеры. (потом можем менять как хотим) Что то типа инициализации.
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    Font font;//шрифт 
	font.loadFromFile("CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	Text text("", font, 15);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	//text.setStyle(Text::Bold);//жирный текст.


    Image map_image;//объект изображения для карты
	map_image.loadFromFile("images/background.png");//загружаем файл для карты
	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом 

/*

    const int WW = 256;
    const int HH = 256;


    Image map_image;//объект изображения для карты
	map_image.loadFromFile("images/background.png");//загружаем файл для карты

    const int delb = 6;
    const int arrb[9] = {1, 1, 1, 1, 9, 1, 1, 1, 1};

    sf::Uint8 *pixelsb = new sf::Uint8[WW*HH*4];
    const sf::Uint8 *pixels1b = new sf::Uint8[WW*HH*4];

	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой

     pixels1b = map_image.getPixelsPtr();

    for(int i = 0; i < WW*HH*4; i += 1) {
        pixelsb[i] = pixels1b[i];
    }

    for(int i = 0; i < WW*HH*4; i += 1) {

        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;
        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;
        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;

    }

    map.update(pixelsb);

	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом 
*/



    /////// BOSS ////////// 


    //sf::Sprite bo = boss();
    //Image bossimg;//объект изображения

    //if(!bossimg.loadFromFile("images/boss.png")) std::cout << "ploho";
	//bossimg.loadFromFile("images/boss.png");//загружаем файл

    /*
    const int WW = 286;
    const int HH = 113;
    Image bossimg;//объект изображения
	bossimg.loadFromFile("images/boss.png");//загружаем файл
    sf::Sprite bosssprite;//создаем объект Sprite(спрайт)

    const int delb = 6;
    const int arrb[9] = {1, 1, 1, 1, 9, 1, 1, 1, 1};

    sf::Uint8 *pixelsb = new sf::Uint8[WW*HH*4];
    const sf::Uint8 *pixels1b = new sf::Uint8[WW*HH*4];

	Texture bosstex;//создаем объект Texture (текстура)
	bosstex.loadFromImage(bossimg);//передаем в него объект Image (изображения)

    pixels1b = bossimg.getPixelsPtr();

    for(int i = 0; i < WW*HH*4; i += 1) {
        pixelsb[i] = pixels1b[i];
    }

    for(int i = 0; i < WW*HH*4; i += 1) {

        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;
        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;
        pixelsb[i] = (pixelsb[i - WW - 4] * arrb[0] + pixelsb[i - WW] * arrb[1] + pixelsb[i - WW + 4] * arrb[2] + pixelsb[i - 4] * arrb[3] + pixelsb[i] * arrb[4] + pixelsb[i + 4] * arrb[5] + pixelsb[i + WW - 4] * arrb[6] + pixelsb[i + WW] * arrb[7] + pixelsb[i + WW + 4] * arrb[8]) / delb;
        i++;

    }

    bosstex.update(pixelsb);
    bosssprite.setTexture(bosstex);
 

	//bosssprite.setTexture(bosstex);//передаём в него объект Texture (текстуры)
    bosssprite.setTextureRect(IntRect(0,0,286,113));
	bosssprite.setPosition(500, 500);//задаем начальные координаты появления спрайта 

    */


    double x[5] = {1,2,3,4,5};
    double N = 5;
    std::complex<double> G[5];

    for(int u=0; u<N; u++){
        for (int n = 0; n < N; n++)
        {
            double w = -2 * 3.1415 * u * n / N;
            std::complex<double> c(sin(w), cos(w)) ;//= std::complex(sin(w), cos(w));
            G[u] += (c * x[n] / N);
        } 
    }

    //std::cout << "hello";




    
    
////////////////////////// end boss /////////////////////////////






// Хуй его знает (поправить)
/*
    const unsigned int W = 150;
    const unsigned int H = 150; // you can change this to full window size later

    sf::Uint8 pixels [(W*H)*(4)];
    //const sf::Uint8 *pByteBuffer = sd::Image::getPixelsPtr();

    Image heroimage1;
    //std::cout << heroimage1.loadFromFile("images/test.png"); 
    heroimage1.loadFromFile("images/test.png");
    //const sf::Uint8 *pixels [W*H*4] = sf::heroimage1::getPixelsPtr();


    Texture herotexture1;
    herotexture1.loadFromImage(heroimage1);

    //heroimage1.LoadFromPixels(150, 150, pixels);

    //herotexture1.create(W, H);

    sf::Sprite sprite(herotexture1); // needed to draw the texture on screen

    sf::Uint8 del = 6;
    sf::Uint8 arr[9] = {1, 1, 1, 1, 9, 1, 1, 1, 1};

    // ...

    for(register int i = 0; i < W*H*4; i += 1) {
   // pixels[i] = r; // obviously, assign the values you need here to form your color
   // pixels[i+1] = g;
   // pixels[i+2] = b;
   // pixels[i+3] = a;

    pixels[i] = (pixels[i - W - 4] * arr[0] + pixels[i - W] * arr[1] + pixels[i - W + 4] * arr[2] + pixels[i - 4] * arr[3] + pixels[i] * arr[4] + pixels[i + 4] * arr[5] + pixels[i + W - 4] * arr[6] + pixels[i + W] * arr[7] + pixels[i + W + 4] * arr[8]) / del;
    i++;
    pixels[i] = (pixels[i - W - 4] * arr[0] + pixels[i - W] * arr[1] + pixels[i - W + 4] * arr[2] + pixels[i - 4] * arr[3] + pixels[i] * arr[4] + pixels[i + 4] * arr[5] + pixels[i + W - 4] * arr[6] + pixels[i + W] * arr[7] + pixels[i + W + 4] * arr[8]) / del;
    i++;
    pixels[i] = (pixels[i - W - 4] * arr[0] + pixels[i - W] * arr[1] + pixels[i - W + 4] * arr[2] + pixels[i - 4] * arr[3] + pixels[i] * arr[4] + pixels[i + 4] * arr[5] + pixels[i + W - 4] * arr[6] + pixels[i + W] * arr[7] + pixels[i + W + 4] * arr[8]) / del;
    i++;
        //pixels[i] = 255;

    }

    herotexture1.update(pixels);

    //usleep(1000);


*/

    //Время
    Clock clock; 

    // Музыка
    Music music;//создаем объект музыки
    music.openFromFile("music.ogg");//загружаем файл
    music.play();//воспроизводим музыку
    music.setVolume(20);

    //Класс игрока
    class Player { // класс Игрока
    private:
        float x, y;
    public:
        float w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
        int dir = 0; //направление (direction) движения игрока
        String File; //файл с расширением
        Image image;//сфмл изображение
        Texture texture;//сфмл текстура
        Sprite sprite;//сфмл спрайт


        const int WW = 150;
        const int HH = 150; // you can change this to full window size later

        const int del = 6;
        const int arr[9] = {1, 1, 1, 1, 9, 1, 1, 1, 1};


        sf::Uint8 *pixels = new sf::Uint8[WW*HH*4];
        const sf::Uint8 *pixels1 = new sf::Uint8[WW*HH*4];

    
        Player(String F, float X, float Y, float W, float H){  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
            File = F;//имя файла+расширение
            w = W; h = H;//высота и ширина

            image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
            texture.loadFromImage(image);//закидываем наше изображение в текстуру
            pixels1 = image.getPixelsPtr();

            for(int i = 0; i < WW*HH*4; i += 1) {
                pixels[i] = pixels1[i];
            }

            //delete[] pixels1;

            for(int i = 0; i < WW*HH*4; i += 1) {

                pixels[i] = (pixels[i - WW - 4] * arr[0] + pixels[i - WW] * arr[1] + pixels[i - WW + 4] * arr[2] + pixels[i - 4] * arr[3] + pixels[i] * arr[4] + pixels[i + 4] * arr[5] + pixels[i + WW - 4] * arr[6] + pixels[i + WW] * arr[7] + pixels[i + WW + 4] * arr[8]) / del;
                i++;
                pixels[i] = (pixels[i - WW - 4] * arr[0] + pixels[i - WW] * arr[1] + pixels[i - WW + 4] * arr[2] + pixels[i - 4] * arr[3] + pixels[i] * arr[4] + pixels[i + 4] * arr[5] + pixels[i + WW - 4] * arr[6] + pixels[i + WW] * arr[7] + pixels[i + WW + 4] * arr[8]) / del;
                i++;
                pixels[i] = (pixels[i - WW - 4] * arr[0] + pixels[i - WW] * arr[1] + pixels[i - WW + 4] * arr[2] + pixels[i - 4] * arr[3] + pixels[i] * arr[4] + pixels[i + 4] * arr[5] + pixels[i + WW - 4] * arr[6] + pixels[i + WW] * arr[7] + pixels[i + WW + 4] * arr[8]) / del;
                i++;
            
            }

            texture.update(pixels);
            
            

            //image.createMaskFromColor(Color(41, 33, 59));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
            //  texture.loadFromImage(image);//закидываем наше изображение в текстуру
            sprite.setTexture(texture);//заливаем спрайт текстурой
            x = X; y = Y;//координата появления спрайта
            sprite.setTextureRect(IntRect(0, 0, w*4, h*4));  //Задаем спрайту один прямоугольник для вывода одного кадра, а не кучи львов сразу. IntRect - приведение типов
            sprite.setTextureRect(IntRect(0, 0, w, h));
    }

    void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
		{
		case 0: dx = speed; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
		case 1: dx = -speed; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
		case 2: dx = 0; dy = speed;   break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
		case 3: dx = 0; dy = -speed;   break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
		}
 
		x += dx*time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
		y += dy*time;//аналогично по игреку
 
		speed = 0;//зануляем скорость, чтобы персонаж остановился.
		sprite.setPosition(x,y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	}

    float getplayercoordinateX(){	//этим методом будем забирать координату Х	
    return x;
	}
	float getplayercoordinateY(){	//этим методом будем забирать координату Y 	
		return y;
	}
};


    float CurrentFrame;

    Player p("hero.png", 400, 300, 37.5, 37.5);//создаем объект p класса player,задаем "hero.png" как имя файла+расширение, далее координата Х,У, ширина, высота.


    while (window.isOpen())
    {

        //Время
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры, чем больше делитель, тем плавнее игра

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
            p.dir = 1; p.speed = 0.1;//dir =1 - направление вверх, speed =0.1 - скорость движения. Заметьте - время мы уже здесь ни на что не умножаем и нигде не используем каждый раз
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            p.sprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*1, 37.5, 37.5)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
            getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            p.dir = 0; p.speed = 0.1;//направление вправо, см выше
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            p.sprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*2, 37.5, 37.5));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
            getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            p.dir = 3; p.speed = 0.1;//направление вниз, см выше
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            p.sprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*3, 37.5, 37.5));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
            getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
            p.dir = 2; p.speed = 0.1;//направление вверх, см выше
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            p.sprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*0, 37.5, 37.5)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
        }
        
        p.update(time);//оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться
        viewmap(time);//функция скроллинга карты, передаем ей время sfml
		changeview();//прикалываемся с камерой вида
		window.setView(view);//"оживляем" камеру в окне sfml
        window.clear();



        		/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(16*0, 16*8, 16, 16)); //если встретили символ пробел, то рисуем 1й квадратик
			if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(16*15, 16*13, 16, 16));//если встретили символ s, то рисуем 2й квадратик
			if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(16*5, 16*7, 16, 16));//если встретили символ 0, то рисуем 3й квадратик
 
 
			s_map.setPosition(j * 16, i * 16);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
 
			window.draw(s_map);//рисуем квадратики на экран
            
		}

              //bossimg);

        //window.draw(bo);
        //window.draw(bosssprite);

        //if ((Keyboard::isKeyPressed(Keyboard::D))) {
            //window.draw(bosssprite);
        //}

        std::ostringstream playerScoreString;    // объявили переменную
		playerScoreString << G[0] << G[1] << G[2] << G[3] << G[4];   //занесли в нее число очков, то есть формируем строку
		text.setString("Furi: ( " + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(view.getCenter().x - 400, view.getCenter().y + 200);//задаем позицию текста, отступая от центра камеры
		window.draw(text);//рисую этот текст


        window.draw(p.sprite);//рисуем спрайт объекта p класса player
        //window.draw(bosssprite);

        window.display();
    }

    return 0;
}