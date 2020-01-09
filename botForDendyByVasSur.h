#include <TXlib.h>

class Bot
{
     public:

        void smena();
        void captertwo();
        void capterthree();
        void capterfour();
        void capterfive();
        int cell();
        int botshot();
        void draw();
        void sprite(HDC a);
        int randomizer();
        Bot();
        ~Bot();
        int upravbot();
        int right();
        int down();
        int left();
        int up();
        int coord();
        void boom(int a);
        void perevod(int a);
        void dvish(int a);
        int boomout();

    private:
        int x, y, wh;
        int xSrc, ySrc, whSrc, time = 1, stoy = 0, urov;
        int shot, xtim, ytim, provx, provy, boomx = -1, boomy = -1;
        int V, bank = 0, poloz, snar = 10;
        HDC text;
};

void Bot::sprite(HDC a)
    {
        text = a;
    }

Bot::Bot()
    {
        x = 8;
        y = 16;
        wh = 50;
        whSrc = 9;
        V = 1;
        xSrc = 1;
        ySrc = 1;
        xtim = x;
        ytim = y;
        urov = 2;

    }
Bot::~Bot()
{
    cout << "Bot OK" << std::endl;
}

int Bot::right()
    {
        if (xtim + 1 < 18)
        {
            xtim++;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 31;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 31;
            time = 1;
        }
        shot = 2;
        return 100 * xtim + ytim;
    }
int Bot::down()
    {
        if (ytim + 1 < 18)
        {
            ytim++;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 31;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 31;
            time = 1;
        }
        shot = 3;
        return 100 * xtim + ytim;
    }
int Bot::left()
    {
        if (xtim - 1 > -1)
        {
            xtim--;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 21;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 21;
            time = 1;
        }
        shot = 4;
        return 100 * xtim + ytim;
    }
int Bot::up()
    {
        if (ytim - 1 > -1)
        {
            ytim--;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 21;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 21;
            time = 1;
        }
        shot = 1;
        return 100 * xtim + ytim;
    }

void Bot::dvish(int a)
    {
        if (a == 3 || a == 5 || a == 2)
        {
            xtim = x;
            ytim = y;
        }
        else if (provx == xtim && provy == ytim)
        {
            xtim = x;
            ytim = y;
        }
        else if (a == 1 || a == 4 || a == 6)
        {
            x = xtim;
            y = ytim;
        }
        if (boomx == x && boomy == y || boomx == xtim && boomy == ytim)
        {
            x = -1;
            y = -1;
            stoy = 1;
        }
    }

int Bot::coord()
    {
        return 100 * x + y;
    }
int Bot::upravbot()
    {
        if (stoy == 0)
        {
            if (bank == 0)
            {
                poloz = randomizer();
                bank = 6;
            }
            bank--;
            if (poloz == 1)
            {
                return up();
            }
            else if (poloz == 2)
            {
                return right();
            }
            else if (poloz == 3)
            {
                return down();
            }
            else if (poloz == 4)
            {
                return left();
            }
            else
            {
            return 100 * x + y;
        }
        }
    }
int Bot::randomizer()
    {
        int a;
        a = rand() % 4 + 1;
    }

void Bot::draw()
    {
        if (stoy == 0)
        {
            Win32::TransparentBlt (txDC(), x * wh, y * wh, wh, wh, text, xSrc, ySrc, whSrc, whSrc, TX_BLACK);
        }
    }


void Bot::perevod(int a)
    {
        provx = a / 100;
        provy = a - a / 100 * 100;
    }

void Bot::boom(int a)
    {
        boomx = a / 100;
        boomy = a - a / 100 * 100;
    }
int Bot::boomout()
    {
        return stoy;
    }

int Bot::botshot()
    {
        if (snar == 16)
        {
            snar--;
            return 1;
        }
        else if (snar == 0)
        {
            snar = 16;
        }
        else if (snar < 16)
        {
            snar--;
        }
        return 0;
    }
int Bot::cell()
    {
        int c;
        c = shot;
        return c;
    }

void Bot::smena()
    {

            if (urov == 5)
            {
                urov++;
                capterfive();
            }
            else if (urov == 4)
            {
                urov++;
                capterfour();
            }
            else if (urov == 3)
            {
                urov++;
                capterthree();
            }
            else if (urov == 2)
            {
                urov++;
                captertwo();
            }
            else if (urov == 6)
            {
                x = -1;
                y = -1;
                xtim = -1;
                ytim = -1;
                stoy = 2;
            }

    }
void Bot::captertwo()
    {
        stoy = 0;
        x = 15;
        y = 16;
        xtim = 15;
        ytim = 16;
    }
void Bot::capterthree()
    {
        stoy = 0;
        x = 16;
        y = 11;
        xtim = 16;
        ytim = 11;
    }
void Bot::capterfour()
    {
        stoy = 0;
        x = 16;
        y = 9;
        xtim = 16;
        ytim = 9;
    }
void Bot::capterfive()
    {
        stoy = 0;
        x = 16;
        y = 9;
        xtim = 16;
        ytim = 9;
    }
