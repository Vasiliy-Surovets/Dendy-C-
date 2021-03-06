
#include <TXlib.h>
#include "tankForDendyByVasSur.h"
#include "mapForDendyByVasSur.h"
#include "shotForDendyByVasSur.h"
#include "botForDendyByVasSur.h"
#include "menuForDendyByVasSur.h"

int main()
{
    txTextCursor(0);
    txCreateWindow(900, 900);

    Tank tank;
    Bot bot;
    Map card;
    Bullet gold;
    Bullet silver;
    Menu menu;
    int i, z = 0, s, g, v = 0, f = 0, c, cv = 0;
    HDC a = txLoadImage("dendyForDendyByVasSur.bmp");
    menu.sprite(a);
    tank.sprite(a);
    bot.sprite(a);
    card.sprite(a);
    silver.sprite(a);
    gold.sprite(a);


    menu.startscreen();



    while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
            txBegin();
            card.draw();

            i = silver.coord();
            tank.boom(i);
            silver.botstoy(tank.boomout());

            tank.perevod(v);
            i = tank.uprav();
            i = card.checkin(i);
            tank.dvish(i);
            tank.draw();

            v = tank.coord();
            bot.perevod(v);

            i = bot.upravbot();
            i = card.checkin(i);

            v = gold.coord();
            bot.boom(v);
            gold.botstoy(bot.boomout());

            bot.dvish(i);

            bot.draw();
            s = tank.cell();
            gold.naprav(s);

            g = bot.cell();
            silver.naprav(g);


            i = tank.coord();
            cv = bot.coord();
            if (GetAsyncKeyState(32) && z == 0)
                z = gold.shot(i);
            if (z == 1)
            {
                i = gold.napravafter();
                i = card.burst(i);
                gold.out(i);
                z = gold.draw();
            }

            c = bot.botshot();

            if (c == 1 && f == 0)
                f = silver.shot(cv);
            if (f == 1)
            {
                cv = silver.napravafter();
                cv = card.burst(cv);
                silver.out(cv);
                f = silver.draw();
            }

            if (bot.boomout() == 2)
            {
                while (GetAsyncKeyState(VK_RETURN) == 0)
                {
                    txSetFillColor(TX_BLACK);
                    txRectangle(0, 0, 900, 900);

                    txSetColor(TX_WHITE);
                    txSelectFont ("Comic Sans MS", 40);
                    txDrawText(0, 0, 900, 900, "������!!! ����� Enter � Escape ��� ������");
                    txSleep(50);
                }
            }

            if (bot.boomout() == 1)
            {
                bot.smena();
                tank.smena();
                card.smena();

                while (GetAsyncKeyState(VK_RETURN) == 0)
                {
                    txSetFillColor(TX_BLACK);
                    txRectangle(0, 0, 900, 900);

                    txSetColor(TX_WHITE);
                    txSelectFont ("Comic Sans MS", 40);
                    txDrawText(0, 0, 900, 900, "�������! ������� Enter ��� �����������");
                    txSleep(50);
                }
            }
            if (tank.boomout() == 1)
            {
                while (GetAsyncKeyState(VK_RETURN) == 0)
                {
                    txSetFillColor(TX_BLACK);
                    txRectangle(0, 0, 900, 900);

                    txSetColor(TX_WHITE);
                    txSelectFont ("Comic Sans MS", 40);
                    txDrawText(0, 0, 900, 900, "��������... ����� Enter � Escape ��� ������");
                    txSleep(50);
                }
            }


            v = bot.coord();
            txSleep(50);
            txEnd();
        }
    txDeleteDC(a);
    return 0;
}
