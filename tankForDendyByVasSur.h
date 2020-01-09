#include <TXlib.h>

class Tank
{
    public:

        void smena();
        void captertwo();
        void capterthree();
        void capterfour();
        void capterfive();
        void boom(int a);
        int boomout();
        int randomizer();
        Tank();
        ~Tank();
        int uprav();
        int upravbot();
        int up();
        void sprite(HDC a);
        void draw();
        int right();
        int down();
        int left();
        void dvish(int a);
        int cell();
        int coord();
        void perevod(int a);

    private:
        int x, y, wh;
        int xSrc, ySrc, whSrc, time = 1;
        int shot, xtim, ytim, provx, provy, boomx = -1, boomy = -1;
        int V, bank = 0, poloz, urov = 2, stoy = 0;
        HDC text;
};

Tank::Tank()
    {
        x = 2;
        y = 10;
        wh = 50;
        whSrc = 9;
        V = 1;
        xSrc = 1;
        ySrc = 1;
        xtim = x;
        ytim = y;

    }
Tank::~Tank()
{
    cout << "Tank OK" << std::endl;
}


int Tank::uprav()
    {
        if (GetAsyncKeyState(87))
        {
            return up();
        }
        else if (GetAsyncKeyState(68))
        {
            return right();
        }
        else if (GetAsyncKeyState(83))
        {
            return down();
        }
        else if (GetAsyncKeyState(65))
        {
            return left();
        }
        else
        {
            return 100 * x + y;
        }
    }

void Tank::draw()
    {
        if (stoy == 0)
        {
            Win32::TransparentBlt (txDC(), x * wh, y * wh, wh, wh, text, xSrc, ySrc, whSrc, whSrc, TX_BLACK);
        }
    }
void Tank::sprite(HDC a)
    {
        text = a;
    }
int Tank::right()
    {
        if (xtim + 1 < 18)
        {
            xtim++;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 11;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 11;
            time = 1;
        }
        shot = 2;
        return 100 * xtim + ytim;
    }
int Tank::down()
    {
        if (ytim + 1 < 18)
        {
            ytim++;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 11;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 11;
            time = 1;
        }
        shot = 3;
        return 100 * xtim + ytim;
    }
int Tank::left()
    {
        if (xtim - 1 > -1)
        {
            xtim--;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 1;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 1;
            time = 1;
        }
        shot = 4;
        return 100 * xtim + ytim;
    }
int Tank::up()
    {
        if (ytim - 1 > -1)
        {
            ytim--;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 1;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 1;
            time = 1;
        }
        shot = 1;
        return 100 * xtim + ytim;
    }
void Tank::dvish(int a)
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
        else if (boomx == x && boomy == y || boomx == xtim && boomy == ytim)
        {
            x = -1;
            y = -1;
            stoy = 1;
        }
        else if (a == 1 || a == 4 || a == 6)
        {
            x = xtim;
            y = ytim;
        }
    }
int Tank::cell()
    {
        int c;
        c = shot;
        return c;
    }
int Tank::coord()
    {
        return 100 * x + y;
    }
int Tank::upravbot()
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
int Tank::randomizer()
    {
        int a;
        a = rand() % 4 + 1;
    }

void Tank::perevod(int a)
    {
        provx = a / 100;
        provy = a - a / 100 * 100;
    }

int Tank::boomout()
    {
        return stoy;
    }

void Tank::boom(int a)
    {
        boomx = a / 100;
        boomy = a - a / 100 * 100;
    }

void Tank::smena()
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
            }
        }
void Tank::captertwo()
    {
        x = 2;
        xtim = 2;
        y = 16;
        ytim = 16;
    }
void Tank::capterthree()
    {
        x = 1;
        xtim = 1;
        y = 6;
        ytim = 6;
    }
void Tank::capterfour()
    {
        x = 1;
        xtim = 1;
        y = 15;
        ytim = 15;
    }
void Tank::capterfive()
    {
        x = 3;
        xtim = 3;
        y = 1;
        ytim = 1;
    }
