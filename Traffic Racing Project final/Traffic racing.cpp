#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<windows.h>
#include "start.h"
int x=850,y=650;
char ch;
void start();
void menu();
int normalmode();
int speedmode();

void instruction();
void scorecard();
void credits();
void gameover();
void exit();
int pause1();
int pause2();
void run_car1();
int enemy_car1();
void run_car_2();
int enemy_car_2();
void levelselection();
//Main function starts from here.
main()
{
    //Calling start(); from user defined header file "start.h"
    start();
    //calling menu function.
    menu();
    return 0;
}
//level select
void levelselection()
{
    readimagefile("img/ngm/levelselect.jpg",0,0,850,650);
    while(1)
    {
        int x,y;
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=50 && y>= 107 && x<=283 && y<=161)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            normalmode();
        }
        else if(x>=50 && y>= 270 && x<=281 && y<=325)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            speedmode();

        }

        else if(kbhit())
        {
            ch=getch();
            while(kbhit())
                getch();
            if(ch==27)
            {
                mciSendString("play snd/sc.wav",0,0,0);
                menu();

            }
        }
        else levelselection();



    }

}
//gameover function.
void gameover()
{
    readimagefile("img/gameover/go1.jpg",0,0,850,650);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        int x,y;
        x= mousex();
        y= mousey();
        if(x>=250 && y>=214 && x<=576 && y<=257 )
        {
            readimagefile("img/gameover/go2.jpg",0,0,850,650);
        }
        else if(x>=254 && y>=334 && x<=570 && y<=376 )
        {
            readimagefile("img/gameover/go3.jpg",0,0,850,650);
        }
        else readimagefile("img/gameover/go1.jpg",0,0,850,650);
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=250 && y>=214 && x<=576 && y<=257 )
        {
            mciSendString("play snd/sc.wav",0,0,0);
            levelselection();
        }
        else if(x>=254 && y>=334 && x<=570 && y<=376 )
        {
            mciSendString("play snd/sc.wav",0,0,0);
            menu();
        }

    }
}
//game pause function.
int pause1()
{
    readimagefile("img/ngm/pause1.jpg",0,0,850,650);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        int x,y;
        x= mousex();
        y= mousey();
        if(x>=200 && y>=292 && x<=360 && y<=324 )
        {
            readimagefile("img/ngm/resume.jpg",0,0,850,650);
        }
        else if(x>=428 && y>=292 && x<=656 && y<=324 )
        {
            readimagefile("img/ngm/pause2.jpg",0,0,850,650);
        }
        else  readimagefile("img/ngm/pause1.jpg",0,0,850,650);
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=428 && y>=292 && x<=656 && y<=324 )
        {
            mciSendString("play snd/sc.wav",0,0,0);
            menu();
        }
        else if(x>=200 && y>=292 && x<=360 && y<=324 )
        {
            mciSendString("play snd/sc.wav",0,0,0);
            mciSendString("resume snd/back.wav",0,0,0);
            readimagefile("img/ngm/back4.jpg",0,0,850,650);
            clearmouseclick(WM_LBUTTONDOWN);
            return 1;
        }
        else if(kbhit())
        {
            ch=getch();
            if(ch==27)
            {
                readimagefile("img/ngm/back4.jpg",0,0,850,650);
                clearmouseclick(WM_LBUTTONDOWN);
                mciSendString("resume snd/back.wav",0,0,0);
                return 1;
            }
        }
        else clearmouseclick(WM_LBUTTONDOWN);
    }
}
int pause2()
{
    readimagefile("img/ngm/pause1.jpg",0,0,850,650);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        int x,y;
        x= mousex();
        y= mousey();
        if(x>=200 && y>=292 && x<=360 && y<=324 )
        {
            readimagefile("img/ngm/resume.jpg",0,0,850,650);
        }
        else if(x>=428 && y>=292 && x<=656 && y<=324 )
        {
            readimagefile("img/ngm/pause2.jpg",0,0,850,650);
        }
        else  readimagefile("img/ngm/pause1.jpg",0,0,850,650);
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=428 && y>=292 && x<=656 && y<=324 )
        {
            mciSendString("play snd/sc.wav",0,0,0);
            menu();
        }
        else if(x>=200 && y>=292 && x<=360 && y<=324 )
        {
            mciSendString("play snd/sc.wav",0,0,0);
            mciSendString("resume snd/back.wav",0,0,0);
            readimagefile("img/ngm/back1.jpg",0,0,850,650);
            clearmouseclick(WM_LBUTTONDOWN);
            return 1;
        }
        else if(kbhit())
        {
            ch=getch();
            if(ch==27)
            {
                readimagefile("img/ngm/back1.jpg",0,0,850,650);
                clearmouseclick(WM_LBUTTONDOWN);
                mciSendString("resume snd/back.wav",0,0,0);
                return 1;
            }
        }
        else clearmouseclick(WM_LBUTTONDOWN);
    }
}
//main menu function.
void menu()
{
    int x,y;
    //checking x,y,coordinates.
    while(1)
    {
        int z=0;
        readimagefile("img/menu/menu.jpg",0,0,850,650);
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            x= mousex();
            y= mousey();
            if(x>=621 && y>= 244 && x<=850 && y<=307)
            {
                readimagefile("img/menu/newgame.jpg",0,0,850,650);
                if(z==0)
                {
                    mciSendString("stop snd/ch.wav",0,0,0);
                    mciSendString("play snd/ch.wav",0,0,0);
                }
                z=1;
            }
            else if(x>=609 && y>= 329 && x<=850 && y<=393)
            {
                readimagefile("img/menu/instruction.jpg",0,0,850,650);
                if(z==0)
                {
                    mciSendString("stop snd/ch.wav",0,0,0);
                    mciSendString("play snd/ch.wav",0,0,0);
                }
                z=1;
            }
            else if(x>=599 && y>= 413 && x<=850 && y<=480)
            {
                readimagefile("img/menu/scorecard.jpg",0,0,850,650);
                if(z==0)
                {
                    mciSendString("stop snd/ch.wav",0,0,0);
                    mciSendString("play snd/ch.wav",0,0,0);
                }
                z=1;
            }
            else if(x>=590 && y>= 497 && x<=850 && y<=563)
            {
                readimagefile("img/menu/credits.jpg",0,0,850,650);
                if(z==0)
                {
                    mciSendString("stop snd/ch.wav",0,0,0);
                    mciSendString("play snd/ch.wav",0,0,0);
                }
                z=1;
            }
            else if(x>=575 && y>= 578 && x<=850 && y<=642)
            {
                readimagefile("img/menu/exit.jpg",0,0,850,650);
                if(z==0)
                {
                    mciSendString("stop snd/ch.wav",0,0,0);
                    mciSendString("play snd/ch.wav",0,0,0);
                }
                z=1;
            }
            else
            {
                readimagefile("img/menu/menu.jpg",0,0,850,650);
                z=0;
            }

        }
        //Selecting option
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=621 && y>= 241 && x<=850 && y<=313)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            //normalmode();
            levelselection();
        }
        else if(x>=609 && y>= 326 && x<=850 && y<=398)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            instruction();
        }

        else if(x>=599 && y>= 410 && x<=850 && y<=485)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            scorecard();
        }
        else if(x>=590 && y>= 494 && x<=850 && y<=568)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            credits();
        }
        else if(x>=575 && y>= 575 && x<=850 && y<=650)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            exit();
        }
        else
            menu();
    }
}
//run_car function for load cars continuously.
void run_car1(int enemycartop[],char carname[][40], int enemycarleft[])
{
    int i;
    for(i=0; i<3; i++)
        readimagefile(carname[i],enemycarleft[i],enemycartop[i]-85,enemycarleft[i]+45,enemycartop[i]);
}
//Enemy_car function for read car file & count scores.
int enemy_car1(int enemycartop[],char carname [][40],int enemycarleft[], int speed,int score)
{
    int i;
    for(i=0; i<3; i++)
    {
        if(enemycartop[i]<750)
        {
            bar(enemycarleft[i],enemycartop[i]-85,enemycarleft[i]+45,enemycartop[i]-95);
            enemycartop[i]+=speed;
            setfillstyle(SOLID_FILL,BLACK);
        }
        else
        {
            sprintf(carname[i],"img/cars/%d.jpg",(rand()%20));
            enemycartop[i]=0;
            score++;
            int x=rand()%3;
            if(x==1)
                enemycarleft[i]=303;
            if(x==2)
                enemycarleft[i]=403;
            if(x==0)
                enemycarleft[i]=503;
            char scores[60];
            sprintf(scores,"%d",score);
            settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
            setcolor(WHITE);
            outtextxy(70,80,scores);
        }
    }
    return score;
}
struct sco
{
    int val;
    char name[20];
};
//This is the main game function.
int normalmode()
{
    int w=-100,x=550,flag=0,f=0,tm,rm,lm,jump=0,y=0,chek=0,mval=2,jval=3;
    char c,carname[5][40],scores[7];
    char levels[1],mvals[1],jvals[1];
    int r=448,l=403,t=545,d=630, speed=5,i,terminate=0,score=0,speedup=1,l3=503,level=0;
    readimagefile("img/ngm/back4.jpg",0,0,850,650);
    setfillstyle(SOLID_FILL,BLACK);
    readimagefile("img/ngm/f.jpg",l,t,r,d);
    readimagefile("img/ngm/r3.jpg",360,w,380,x);
    readimagefile("img/ngm/r3.jpg",472,w,488,x);
    mciSendString("play snd/start.wav",0,0,0);
    delay(3000);

    int enemycartop[5]= {0,-225,-450,-700,0},enemycarleft[6]= {l3,l,l,r,l3,r};

    for(i=0; i<3; i++)
        sprintf(carname[i],"img/cars/%d.jpg",(rand()%20));
    while(!terminate)
    {
        mciSendString("play snd/back.wav",0,0,0);
        if(jump==0)
            readimagefile("img/ngm/f.jpg",l,t,r,d);
        readimagefile("img/ngm/r3.jpg",360,w,380,x);
        readimagefile("img/ngm/r3.jpg",472,w,488,x);
        w=w+7;
        x=x+7;
        if(x>750)
        {
            w=-100;
            x=550;
        }
        //Calling run_car();
        run_car1(enemycartop,carname,enemycarleft);
        score=enemy_car1(enemycartop,carname,enemycarleft,speed,score);
        sprintf(levels,"%d",level);
        settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
        setcolor(WHITE);
        outtextxy(650,125,levels);
        sprintf(mvals,"%d",mval);
        settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
        setcolor(WHITE);
        outtextxy(77,424,mvals);
        sprintf(jvals,"%d",jval);
        settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
        setcolor(WHITE);
        outtextxy(70,260,jvals);

        if(y==0)
        {
            if(score%10==0)
            {
                if(speedup==1)
                {
                    level=level+30;
                    speedup=0;
                    mval++;
                    if(mval>5)
                        mval=5;
                    else if(mval<0)
                    {
                        mval=0;
                    }
                    speed=speed+2;
                    if(speed>10)
                        speed=10;
                }
            }
            if(score%15==0)
            {
                if(speedup==1)
                    jval++;
                if(jval>5) jval=5;
            }
            else if(score%10!=0) speedup=1;
            if(GetAsyncKeyState(VK_SHIFT))
            {
                if(jval>0)
                {
                    y=1;
                    jump=1;
                    jval--;
                }
            }
            if(GetAsyncKeyState(VK_CONTROL))
            {
                if(mval>0)
                {
                    y=1;
                    f=1;
                    tm=t;
                    lm=l;
                    rm=r;
                    mciSendString("stop snd/missile.wav",0,0,0);
                    mciSendString("play snd/missile.wav",0,0,0);
                }
            }
            if(kbhit())
            {
                c=getch();
                if(c==KEY_LEFT)
                {
                    if(l>=394 && l<=540)
                    {
                        bar(l,t,r,d+2);
                        l=l-100;
                        r=r-100;
                        readimagefile("img/ngm/f.jpg",l,t,r,d);
                    }


                }
                else if(c==KEY_RIGHT)
                {
                    if(l>=294 && l<=420)
                    {
                        bar(l,t,r,d+2);
                        l=l+100;
                        r=r+100;
                        readimagefile("img/ngm/f.jpg",l,t,r,d);
                    }
                }
                else if(c==27)
                {
                    mciSendString("pause snd/back.wav",0,0,0);
                    pause1();
                }
            }
        }
        if(f==1)
        {
            bar(lm+14,tm,rm-12,tm+50);
            readimagefile("img/ngm/missile.gif",lm+15,tm-30,rm-15,tm);
            tm=tm-30;
        }
        for(i=0; i<3; i++) //Printing missile fire.
        {
            if(enemycarleft[i]==l)
            {
                if((tm-20)-enemycartop[i]<=0)
                {
                    mciSendString("play snd/exp.mp3",0,0,0);
                    readimagefile("img/ngm/exp1.jpg",enemycarleft[i],enemycartop[i]-100,enemycarleft[i]+45,enemycartop[i]);
                    delay(50);
                    readimagefile("img/ngm/exp2.jpg",enemycarleft[i],enemycartop[i]-100,enemycarleft[i]+45,enemycartop[i]);
                    delay(100);
                    bar(enemycarleft[i],enemycartop[i]-100,enemycarleft[i]+45,enemycartop[i]+50);
                    enemycartop[i]=-300;
                    tm=750;
                    f=0;
                    y=0;
                    mval--;
                    if(mval<0)
                    {
                        mval=0;
                    }
                    break;
                }
            }
        }
        //Jump feature runs here.
        if(jump==1)
        {
            readimagefile("img/ngm/f.jpg",l-7,t-30,r+7,d);
            chek++;
            if(chek>35)
            {
                bar(l-7,t-30,r+7,d);
                enemycartop[i]=-50;
                chek=0;
                jump=0;
                //bar(390,450,460,650);
                y=0;
            }
        }
        //Detecting collisions..
        if (jump==0)
        {
            for(i=0; i<3; i++)
            {
                if(enemycarleft[i]==l)
                {
                    if((t-enemycartop[i]<=0)||(t-enemycartop[i]<-85))
                    {
                        delay(1000);
                        terminate=1;
                    }
                }
            }
        }
        // calling gameover();
        if (terminate ==1)
        {
            readimagefile("img/ngm/exp2.jpg",l,t,r,d);
            delay(200);
            mciSendString("stop snd/back.wav",0,0,0);
            mciSendString("play snd/exp.mp3",0,0,0);

        }


    }
    while(kbhit())getch();

    setcolor(WHITE);
    settextstyle(8,HORIZ_DIR,4);
    readimagefile("file/board.jpg",0,0,850,650);
    outtextxy(265,150,"Enter Your Name:");

    int a=0;
    char write[50];
    write[0]='\0';
    while(kbhit()) getch();
    while(1)
    {
        char c=getch();
        if(c==13)
            break;
        else if(c==8)
            a-=2;
        else
            write[a]=c;
        a++;

        write[a]='\0';
        bar(280,200,570,250);
        outtextxy(290,200,write);
    }


    int j,k;
    struct sco entry[10],temp;
    FILE *in,*fp,*wr1;
    in = fopen("scoresfile.txt","a");
    fprintf(in,"%d %s\n",score,write);
    fclose(in);


    fp=fopen("scoresfile.txt","r");
    for(k=0; k<10; k++)
        fscanf(fp,"%d %s",&entry[k].val,&entry[k].name);
    fclose(fp);


    for(j=9; j>0; j--)
        if(entry[j].val>entry[j-1].val)
        {
            temp=entry[j];
            entry[j]=entry[j-1];
            entry[j-1]=temp;
        }
    wr1=fopen("scoresfile.txt","w");
    for(j=0; j<9; j++)
        fprintf(wr1,"%d %s\n",entry[j].val,entry[j].name);
    fclose(wr1);

    PlaySound(NULL, 0, 0);
    char highscores[10];
    readimagefile("img/gameover/gameover5.jpg",0,0,850,650);
    int s=score,hs=entry[0].val;
    sprintf(scores,"%d",s);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
    setcolor(WHITE);
    outtextxy(450,432,scores);
    sprintf(highscores,"%d",hs);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
    setcolor(WHITE);
    outtextxy(450,533,highscores);
    if(s>=entry[0].val)
    {
        setcolor(RED);
        settextstyle(8,HORIZ_DIR,4);
        outtextxy(30,593,"Congrats!! You made a new high score!!");

    }
    delay(2000);
    gameover();
    return 1;
}
//speedmode
void run_car_2(int enemycartop2[],char carname[][40], int enemycarleft2[])
{
    int i;
    for(i=0; i<5; i++)
        readimagefile(carname[i],enemycarleft2[i],enemycartop2[i]-85,enemycarleft2[i]+45,enemycartop2[i]);
}
int enemy_car_2(int enemycartop2[],char carname [][40],int enemycarleft2[], int speed,int score)
{
    int i;
    for(i=0; i<5; i++)
    {
        if(enemycartop2[i]<750)
        {
            bar(enemycarleft2[i],enemycartop2[i]-85,enemycarleft2[i]+45,enemycartop2[i]-125);
            enemycartop2[i]+=speed;
            setfillstyle(SOLID_FILL,BLACK);
        }
        else
        {
            int v=(rand()%20);
            sprintf(carname[i],"img/cars/%d.jpg",v);
            enemycartop2[i]=0;
            score++;
            bar(205,630,655,650);
            int x=rand()%5;
            if(x==1)
                enemycarleft2[i]=205;
            if(x==2)
                enemycarleft2[i]=305;
            if(x==0)
                enemycarleft2[i]=405;
            if(x==3)
                enemycarleft2[i]=505;
            if(x==4)
                enemycarleft2[i]=605;
            char scores[60];
            sprintf(scores,"%d",score);
            settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
            setcolor(WHITE);
            outtextxy(20,80,scores);
        }
    }
    return score;
}
int speedmode()
{
    int w=-100,x=550,level=0;
    char levels[1];
    int r=450,l=405,t=545,d=630, speed=5,i,terminate=0,score=0,speedup=1,x1=205,x2=305,x3=405,x4=505,x5=605;

    readimagefile("img/ngm/back6.jpg",0,0,850,650);

    readimagefile("img/ngm/f2.jpg",l,t,r,d);
    setfillstyle(SOLID_FILL,BLACK);
    mciSendString("play snd/start.wav",0,0,0);
    int enemycartop2[7]= {0,-550,-225,-450,-700,-900,0},enemycarleft2[7]= {x2,x4,x1,x3,x1,x4,x2};
    char c,carname[5][40],scores[7];
    for(i=0; i<5; i++)
        sprintf(carname[i],"img/cars/%d.jpg",(rand()%20));
    while(!terminate)
    {
        mciSendString("play snd/back.wav",0,0,0);
        readimagefile("img/ngm/r3.jpg",280,w,285,x);
        readimagefile("img/ngm/r3.jpg",378,w,383,x);
        readimagefile("img/ngm/r3.jpg",476,w,481,x);
        readimagefile("img/ngm/r3.jpg",574,w,579,x);
        w=w+15;
        x=x+15;
        if(x>750)
        {
            w=-100;
            x=550;
        }

        run_car_2(enemycartop2,carname,enemycarleft2);
        score=enemy_car_2(enemycartop2,carname,enemycarleft2,speed,score);
        sprintf(levels,"%d",level);
        settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
        setcolor(WHITE);
        outtextxy(710,85,levels);
        if(score%20==0)
        {
            if(speedup==1)
            {
                level++;
                speedup=0;
            }
        }
        else if(score%20!=0) speedup=1;
        if(kbhit())
        {

            c=getch();
            if(c==KEY_LEFT)
            {
                if(l>=220 && l<=700)
                {
                    bar(l,t,r,d+2);
                    l=l-100;
                    r=r-100;
                    readimagefile("img/ngm/f2.jpg",l,t,r,d);
                }


            }
            else if(c==KEY_RIGHT)
            {
                if(l>=200 && l<=590)
                {
                    bar(l,t,r,d+2);
                    l=l+100;
                    r=r+100;
                    readimagefile("img/ngm/f2.jpg",l,t,r,d);
                }
            }

            else if(c==27)
            {
                pause2();
            }
            else if(c==115)
            {
                speed=speed+5;
                if (speed>40)
                    speed=40;
            }
            else if(c==100)
            {
                speed=speed-5;
                if(speed<5);
                speed=5;
            }
        }
        for(i=0; i<5; i++) // accident
        {
            if(enemycarleft2[i]==l)
            {
                if((t-enemycartop2[i]<=0))
                {
                    delay(200);
                    terminate=1;
                }
            }
        }
        if (terminate ==1)
        {
            readimagefile("img/ngm/exp2.jpg",l,t,r,d);
            delay(200);
            mciSendString("stop snd/back.wav",0,0,0);
            mciSendString("play snd/exp.mp3",0,0,0);

        }
    }
    while(kbhit())getch();

    setcolor(WHITE);
    settextstyle(8,HORIZ_DIR,4);
    readimagefile("file/board2.jpg",0,0,850,650);
    outtextxy(265,150,"Enter Your Name:");

    int a=0;
    char write[50];
    write[0]='\0';
    while(kbhit()) getch();
    while(1)
    {
        char c=getch();
        if(c==13)
            break;
        else if(c==8)
            a-=2;
        else
            write[a]=c;
        a++;

        write[a]='\0';
        bar(280,200,570,250);
        outtextxy(290,200,write);
    }


    int j,k;
    struct sco entry2[10],temp;
    FILE *in,*fp,*wr1;
    in = fopen("scorefile2.txt","a");
    fprintf(in,"%d %s\n",score,write);
    fclose(in);


    fp=fopen("scorefile2.txt","r");
    for(k=0; k<10; k++)
        fscanf(fp,"%d %s",&entry2[k].val,&entry2[k].name);
    fclose(fp);


    for(j=9; j>0; j--)
        if(entry2[j].val>entry2[j-1].val)
        {
            temp=entry2[j];
            entry2[j]=entry2[j-1];
            entry2[j-1]=temp;
        }
    wr1=fopen("scorefile2.txt","w");
    for(j=0; j<9; j++)
        fprintf(wr1,"%d %s\n",entry2[j].val,entry2[j].name);
    fclose(wr1);
    char highscores[10];
    readimagefile("img/gameover/gameover5.jpg",0,0,850,650);
    int s=score,hs=entry2[0].val;
    sprintf(scores,"%d",s);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
    setcolor(WHITE);
    outtextxy(450,432,scores);
    sprintf(highscores,"%d",hs);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
    setcolor(WHITE);
    outtextxy(613,533,highscores);
    if(s>=entry2[0].val)
    {
        setcolor(WHITE);
        settextstyle(8,HORIZ_DIR,4);
        outtextxy(30,593,"Congrats!! You made a new high score!!");

    }

    delay(2000);
    gameover();
    return 1;

}
//score card function
void scorecard()
{
    while(1)
    {
        char c;
        readimagefile("img/menu/scorecard1.jpg",0,0,850,650);
        setcolor(WHITE);
        settextstyle(8,HORIZ_DIR,4);
        outtextxy(340,270,"Normal Mode");
        setcolor(WHITE);
        outtextxy(350,380,"Speed Mode");
        //Normal mode
        setcolor(WHITE);
        settextstyle(8,HORIZ_DIR,3);
        FILE *leader1;
        leader1=fopen("scoresfile.txt","r");
        int i=3, j=300;


        while(i--)
        {
            int val;
            char name[30], vals[60], names[40];
            fscanf(leader1,"%d %s",&val,&name);
            sprintf(names,"%s                           ",name,val);
            sprintf(vals,"%d",val);
            outtextxy(200,j,names);
            outtextxy(550,j,vals);
            j+=20;
        }

        fclose(leader1);
        //Speed mode
        setcolor(WHITE);
        settextstyle(8,HORIZ_DIR,3);
        FILE *leader2;
        leader2=fopen("scorefile2.txt","r");
        int p=3, q=420;


        while(p--)
        {
            int val;
            char name[30], vals[60], names[40];
            fscanf(leader2,"%d %s",&val,&name);
            sprintf(names,"%s                           ",name,val);
            sprintf(vals,"%d",val);
            outtextxy(200,q,names);
            outtextxy(550,q,vals);
            q+=20;
        }

        fclose(leader2);
        c=getch();


        if(c==27)
        {
            PlaySound(TEXT("snd/sc.wav"),NULL,SND_SYNC);
            menu();
        }
    }


}
//Instruction function
void instruction()
{
    initwindow(850,650,"Traffic Racing");
    while(1)
    {
        readimagefile("img/menu/instruction1.jpg",0,0,850,650);
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            x=mousex();
            y=mousey();
            if(x>=25 && y>=583 && x<=152 && y<=630)
            {
                readimagefile("img/menu/instruction2.jpg",0,0,850,650);
            }
            else readimagefile("img/menu/instruction1.jpg",0,0,850,650);
        }
        getmouseclick(WM_LBUTTONDOWN,x,y);
        int x,y;
        x=mousex();
        y=mousey();
        if(x>=25 && y>=583 && x<=152 && y<=630)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            menu();
        }
        else instruction();
    }
}
//credits function.
void credits()
{
    initwindow(850,650,"Traffic Racing");
    readimagefile("menu/c/credits0.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits1.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits2.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits3.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits4.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits5.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits6.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits7.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits8.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits9.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits10.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits11.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits12.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits13.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits14.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits15.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits16.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits17.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits18.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits19.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits20.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits21.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits22.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits23.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits24.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits25.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits26.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits27.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits28.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits29.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits30.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits31.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits32.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits33.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits34.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits35.jpg",0,0,850,650);
    delay(5);
    readimagefile("img/crd/credits36.jpg",0,0,850,650);
    while(1)
    {

        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            x=mousex();
            y=mousey();
            if(x>=632 && y>=552 && x<=804 && y<=617)
            {

                readimagefile("img/crd/creditsback.jpg",0,0,850,650);
            }
            else
            {
                readimagefile("img/crd/credits37.jpg",0,0,850,650);
            }
        }
        getmouseclick(WM_LBUTTONDOWN,x,y);
        int x,y;
        x=mousex();
        y=mousey();
        if(x>=632 && y>=552 && x<=804 && y<=617)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            menu();
        }
        else credits();
    }
}


//Exit function to get player choice.
void exit()
{

    while(1)
    {
        readimagefile("img/menu/exitmenu.jpg",0,0,850,650);
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            x=mousex();
            y=mousey();
            if(x>=241 && y>=262 && x<=375 && y<=326)
            {
                readimagefile("img/menu/exitmenuy.jpg",0,0,850,650);
            }
            else if(x>=488 && y>=263 && x<=592 && y<=333)
            {
                readimagefile("img/menu/exitmenun.jpg",0,0,850,650);
            }
            else readimagefile("img/menu/exitmenu.jpg",0,0,850,650);
        }
        getmouseclick(WM_LBUTTONDOWN,x,y);
        int x,y;
        x=mousex();
        y=mousey();
        if(x>=241 && y>=262 && x<=375 && y<=326)
            exit(0);
        if(x>=488 && y>=263 && x<=592 && y<=333)
        {
            mciSendString("play snd/sc.wav",0,0,0);
            menu();
        }
        else exit();
    }
}
//Thats all. Thank you :)
