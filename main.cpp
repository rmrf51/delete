#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);




// Хуй его знает (поправить)

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









    //Время
    Clock clock; 

    // Музыка
    Music music;//создаем объект музыки
    music.openFromFile("music.ogg");//загружаем файл
    music.play();//воспроизводим музыку
    music.setVolume(20);

    //Класс игрока
    class Player { // класс Игрока
    public:
        float x, y, w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
        int dir = 0; //направление (direction) движения игрока
        String File; //файл с расширением
        Image image;//сфмл изображение
        Texture texture;//сфмл текстура
        Sprite sprite;//сфмл спрайт
    
        Player(String F, float X, float Y, float W, float H){  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
            File = F;//имя файла+расширение
            w = W; h = H;//высота и ширина
            image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
            image.createMaskFromColor(Color(41, 33, 59));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
            texture.loadFromImage(image);//закидываем наше изображение в текстуру
            sprite.setTexture(texture);//заливаем спрайт текстурой
            x = X; y = Y;//координата появления спрайта
            sprite.setTextureRect(IntRect(0, 0, w, h));  //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
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
};

    /* Image heroimage;
    heroimage.loadFromFile("image/hero.png");

    Texture herotexture;
    herotexture.loadFromImage(heroimage);

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(0,0,37.5,37.5));//получили нужный нам прямоугольник
    herosprite.setPosition(50,25); */

    float CurrentFrame;

    Player p("hero.png",150,150,37.5, 37.5);//создаем объект p класса player,задаем "hero.png" как имя файла+расширение, далее координата Х,У, ширина, высота.
 

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
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            p.dir = 0; p.speed = 0.1;//направление вправо, см выше
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            p.sprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*2, 37.5, 37.5));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            p.dir = 3; p.speed = 0.1;//направление вниз, см выше
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            p.sprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*3, 37.5, 37.5));  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
        }
        
        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
            p.dir = 2; p.speed = 0.1;//направление вверх, см выше
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            p.sprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*0, 37.5, 37.5)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
        }
        
        p.update(time);//оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться
        
        window.clear();
        window.draw(p.sprite);//рисуем спрайт объекта p класса player
        window.display();
    }

    return 0;
}