// HMI2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int ROCK1 = 0;
int PAPER1 = 0;
int SCISSORS1 = 0;
int ROCK2 = 0;
int PAPER2 = 0;
int SCISSORS2 = 0;
int choicePlayer1 = 0;
int choicePlayer2 = 0;
int timeCount = 0;
int flag = 0;

int winersCounter1 = 0;
int winersCounter2 = 0;

/*
void MyFilter(Mat& in, Mat& out) 
{
    uchar* ptr = in.ptr();

    float W[3][3] = { {1,0,-1}, {1,0,-1} ,{1,0,-1} };

    for(int y = 1; y < in.rows-1; y++)
        for (int x = 1; x < in.cols-1; x++) 
        {
            int i = y * in.cols * 3 + 3 * x;
            int B = ptr[i];

            int j = y * in.cols * 3 + 3 * (x+1);
            int B2 = ptr[j];


            

            if(abs(B-B2)<1)
            { 
                ptr[i] = 0; ptr[i + 1] = 0; ptr[i + 2] = 0;
            }



            int i = (y * (3 * in.cols)) + (3 * x);
            int B = ptr[i];
            int G = ptr[i + 1];
            int R = ptr[i + 2];



            int I = (int)(B + G + R) / 3.0;
            //ptr[i]=I;
            //ptr[i + 1]=I;
            //ptr[i + 2]=I;




            int j = (y * (in.cols)) + (x);
            //ptr_out[j] = I;
            
        }

}
*/
/*
void Gris(Mat& in, Mat& out)
{
    uchar* ptr = in.ptr();
    uchar* ptr_out = out.ptr();

    float W[3][3] = { {1,0,-1},{1,0,-1},{1,0,-1} };
    //1 0 -1
    //1 0 -1
    //1 0 -1

    for (int y = 1; y < in.rows - 1; y++)
        for (int x = 1; x < in.cols - 1; x++)
        {
            int i = (y * (3 * in.cols)) + (3 * x);
            int B = ptr[i];
            int G = ptr[i + 1];
            int R = ptr[i + 2];
            int I = (int)(B + G + R) / 3.0;
            //ptr[i]=I;
            //ptr[i + 1]=I;
            //ptr[i + 2]=I;
            int j = (y * (in.cols)) + (x);
            ptr_out[j] = I;
        }
}
*/
/*
int main2()
{
    
    cout << "Create video capture\n";
    string window_name = "video";
    namedWindow(window_name); //resizable window;
    Mat frame, frame2;

    VideoCapture capture(0);


    for (;;)
    {
        capture >> frame2;
        if (frame2.empty()) break;
        MyFilter(frame2, frame);
        imshow(window_name, frame2);
        char key = (char)waitKey(5); //delay N millis, usually long enough to display and capture input
    }
    
}
*/
/*
void Gris(Mat& in, Mat& out)
{
    uchar* ptr = in.ptr();
    uchar* ptr_out = out.ptr();



    float W[3][3] = { {1,0,-1},{1,0,-1},{1,0,-1} };
    //1 0 -1
    //1 0 -1
    //1 0 -1



    int mx = 639, my = 479;
    int Mx = 0, My = 0;



    for (int y = 1; y < in.rows - 1; y++)
        for (int x = 1; x < in.cols - 1; x++)
        {
            int i = (y * (3 * in.cols)) + (3 * x);
            int B = ptr[i];
            int G = ptr[i + 1];
            int R = ptr[i + 2];



            int I = (int)(B + G + R) / 3.0;



            int j = (y * (in.cols)) + (x);
            if (abs(B - 75) < 30 && abs(G - 93) < 30 && abs(R - 153) < 30)
            {
                if (x < mx) { mx = x; }
                if (x > Mx) { Mx = x; }
                if (y < my) { my = y; }
                if (y > My) { My = y; }




                ptr_out[j] = I;
                ptr[i] = 255;
                ptr[i + 1] = 0;
                ptr[i + 2] = 0;
            }
            else { ptr_out[j] = 0; }





        }



    cv::rectangle(in, cv::Rect(Point(mx, my), Point(Mx, My)), cv::Scalar(255, 0, 0));



}
*/
//filtro de grises (NO SE OCUPA PARA EL JUEGO)
void Gris(Mat& in, Mat& out)
{
    uchar* ptr = in.ptr();
    uchar* ptr_out = out.ptr();

    float W[3][3] = { {1,0,-1},{1,0,-1},{1,0,-1} };
    //1 0 -1
    //1 0 -1
    //1 0 -1
    int mx = 639, my = 479;
    int Mx = 0, My = 0;

    for (int y = 1; y < in.rows - 1; y++)
        for (int x = 1; x < in.cols - 1; x++)
        {
            int i = (y * (3 * in.cols)) + (3 * x);
            int B = ptr[i];
            int G = ptr[i + 1];
            int R = ptr[i + 2];

            int I = (int)(B + G + R) / 3.0;

            int j = (y * (in.cols)) + (x);
            if (abs(B - 95) < 30 && abs(G - 120) < 30 && abs(R - 90) < 30)
            {
                if (x < mx) { mx = x; }
                if (x > Mx) { Mx = x; }
                if (y < my) { my = y; }
                if (y > My) { My = y; }

                ptr_out[j] = I;
                ptr[i] = 255;
                ptr[i + 1] = 0;
                ptr[i + 2] = 0;
            }
            else { ptr_out[j] = 0; }
        }
    cv::rectangle(in, cv::Rect(Point(mx, my), Point(Mx, My)), cv::Scalar(255, 0, 0));
    
}
void Gris2(Mat& in, Mat& out)
{
    uchar* ptr = in.ptr();
    uchar* ptr_out = out.ptr();

    float W[3][3] = { {1,0,-1},{1,0,-1},{1,0,-1} };
    //1 0 -1
    //1 0 -1
    //1 0 -1
    int mx = 639, my = 479;
    int Mx = 0, My = 0;

    for (int y = 1; y < in.rows - 1; y++)
        for (int x = 1; x < in.cols - 1; x++)
        {
            int i = (y * (3 * in.cols)) + (3 * x);
            int B = ptr[i];
            int G = ptr[i + 1];
            int R = ptr[i + 2];

            int I = (int)(B + G + R) / 3.0;

            int j = (y * (in.cols)) + (x);
            if (abs(B - 80) < 30 && abs(G - 103) < 30 && abs(R - 115) < 30)
            {
                if (x < mx) { mx = x; }
                if (x > Mx) { Mx = x; }
                if (y < my) { my = y; }
                if (y > My) { My = y; }

                ptr_out[j] = I;
                ptr[i] = 255;
                ptr[i + 1] = 0;
                ptr[i + 2] = 0;
            }
            else { ptr_out[j] = 0; }
        }
    cv::rectangle(in, cv::Rect(Point(mx + 10, my + 10), Point(Mx + 10, My + 10)), cv::Scalar(0, 255, 0));

}
/*void Rectangle(Mat& in)
{
    cv::Rect r = cv::Rect(Point(270, 130), Point(275, 256));
    cv::rectangle(in, r, cv::Scalar(255, 255, 0), 2);

}*/
/*void Gato(Mat& in)
{
    cv::Rect r = cv::Rect(Point(270, 130), Point(275, 526));
    //cv::Rect r = Rect(270, 130, 20, 30);
    //cv::rectangle(in,r, cv::Scalar(255, 255, 0),2);

    cv::line(in, Point(200, 130), Point(200, 426), cv::Scalar(255, 255, 250), 8);
    cv::line(in, Point(400, 130), Point(400, 426), cv::Scalar(255, 255, 250), 8);
    cv::line(in, Point(100, 200), Point(500, 200), cv::Scalar(255, 255, 250), 8);
    cv::line(in, Point(100, 400), Point(500, 400), cv::Scalar(255, 255, 250), 8);
}*/
bool choice(Point p, Rect re)
{
    bool result = false;
    if ((p.x > re.x) && (p.y > re.y) && (p.x<re.br().x) && (p.y < re.br().y)) { return true; }
    return false;
}
//lineas verticales
void RPS(Mat& in)
{
    cv::Rect r = cv::Rect(Point(270, 130), Point(275, 526));

    cv::line(in, Point(0, 155), Point(250, 155), cv::Scalar(255, 255, 250), 2);
    cv::line(in, Point(400, 155), Point(700, 155), cv::Scalar(255, 255, 250), 2);

    cv::line(in, Point(0, 333), Point(250, 333), cv::Scalar(255, 255, 250), 2);
    cv::line(in, Point(400, 333), Point(700, 333), cv::Scalar(255, 255, 250), 2);

}
//jugador1
void Prom(Mat& in)
{
    uchar* ptr = in.ptr();
    float mediax = 0;
    float mediay = 0; 
    float total = 0;

    for (int y = 1; y < in.rows - 1; y++)
        for (int x = 1; x < in.cols - 1; x++)
        {
            int i = (y * (3 * in.cols)) + (3 * x);
            int B = ptr[i];
            int G = ptr[i + 1];
            int R = ptr[i + 2];

            if (abs(B - 65) < 30 && abs(G - 70) < 30 && abs(R - 170) < 30)
            {
                mediax += x;
                mediay += y;
                total++;
                
            }
        }

    mediax = mediax / total;
    mediay = mediay / total; 
    cv::line(in,Point(mediax - 10, mediay - 10), Point(mediax + 10, mediay + 10), cv::Scalar(0, 0, 255),4);
    cv::line(in,Point(mediax - 10, mediay + 10), Point(mediax + 10, mediay - 10), cv::Scalar(0, 0, 255),4);

    if (choice(Point(mediax, mediay), Rect(400, 0, 250, 155)))
    {
        PAPER1 = 0;
        SCISSORS1 = 0;
        Point center(500, 100);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(0, 0, 255), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(0, 0, 255), 4);
        ROCK1++;
        if (ROCK1 > 30)
        {
            PAPER1 = 0;
            SCISSORS1 = 0;
            timeCount = 0;
            choicePlayer1 = 1;
        }
    }

    if (choice(Point(mediax, mediay), Rect(400, 155, 250, 155)))
    {
        ROCK1 = 0;
        SCISSORS1 = 0;
        Point center(500, 250);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(0, 0, 255), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(0, 0, 255), 4);
        PAPER1++;
        if (PAPER1 > 30)
        {
            ROCK1 = 0;
            SCISSORS1 = 0;
            timeCount = 0;
            choicePlayer1 = 2;
        }
    }

    if (choice(Point(mediax, mediay), Rect(400, 355, 250, 155)))
    {
        ROCK1 = 0;
        PAPER1 = 0;
        Point center(500, 400);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(0, 0, 255), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(0, 0, 255), 4);
        SCISSORS1++;
        if (SCISSORS1 > 30)
        {
            ROCK1 = 0;
            PAPER1 = 0;
            timeCount = 0;
            choicePlayer1 = 3;
        }
    }

}
//jugador2
void Prom2(Mat& in)
{
    uchar* ptr = in.ptr();
    float mediax = 0;
    float mediay = 0;
    float total = 0;

    for (int y = 1; y < in.rows - 1; y++)
        for (int x = 1; x < in.cols - 1; x++)
        {
            int i = (y * (3 * in.cols)) + (3 * x);
            int B = ptr[i];
            int G = ptr[i + 1];
            int R = ptr[i + 2];

            if (abs(B - 150) < 30 && abs(G - 150) < 30 && abs(R - 150) < 30)
            {
                mediax += x;
                mediay += y;
                total++;

            }
        }
    mediax = mediax / total;
    mediay = mediay / total;
    cv::line(in, Point(mediax - 10, mediay - 10), Point(mediax + 10, mediay + 10), cv::Scalar(255, 0, 0), 4);
    cv::line(in, Point(mediax - 10, mediay + 10), Point(mediax + 10, mediay - 10), cv::Scalar(255, 0, 0), 4);

    if (choice(Point(mediax, mediay), Rect(0, 0, 250, 155)))
    {
        PAPER2 = 0;
        SCISSORS2 = 0;
        Point center(100, 100);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(255, 0, 0), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(255, 0, 0), 4);
        ROCK2++;
        if (ROCK2 > 30)
        {
            PAPER2 = 0;
            SCISSORS2 = 0;
            timeCount = 0;
            choicePlayer2 = 1;
        }
    }

    if (choice(Point(mediax, mediay), Rect(0, 155, 250, 155)))
    {
        ROCK2 = 0;
        SCISSORS2 = 0;
        Point center(100, 250);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(255, 0, 0), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(255, 0, 0), 4);
        PAPER2++;
        if (PAPER2 > 30)
        {
            ROCK2 = 0;
            SCISSORS2 = 0;
            timeCount = 0;
            choicePlayer2 = 2;
        }
    }

    if (choice(Point(mediax, mediay), Rect(0, 355, 250, 155)))
    {
        ROCK2 = 0;
        PAPER2 = 0;
        Point center(100, 400);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(255, 0, 0), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(255, 0, 0), 4);
        SCISSORS2++;
        if (SCISSORS2 > 30)
        {
            PAPER2 = 0;
            ROCK2 = 0;
            timeCount = 0;
            choicePlayer2 = 3;
        }
    }
}
//
void playersChoice(Mat& in)
{
    if (choicePlayer1 == 0)
    {
        Point center(250, 100);
        int rad = 0;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(0, 0, 0));
    }
    if(choicePlayer1==1)
    {
        Point center(500, 100);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
    }
    if (choicePlayer1 == 2)
    {
        Point center(500, 250);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
    }
    if (choicePlayer1 == 3)
    {
        Point center(500, 400);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
    }
    //////////

    if (choicePlayer2 == 0)
    {
        Point center(250, 100);
        int rad = 0;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(0, 0, 0));
    }
    if (choicePlayer2 == 1)
    {
        Point center(100, 100);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
    }
    if (choicePlayer2 == 2)
    {
        Point center(100, 250);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
    }
    if (choicePlayer2 == 3)
    {
        Point center(100, 400);
        int rad = 30;
        cv::line(in, Point(center.x - rad, center.y - rad), Point(center.x + rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
        cv::line(in, Point(center.x + rad, center.y - rad), Point(center.x - rad, center.y + rad), cv::Scalar(221, 250, 15), 4);
    }




}
//WinersCounts
void WinP1(Mat& in)
{
    if (winersCounter1==1) {
        Point center(620, 10);
        cv::line(in, Point(center.x, center.y), Point(center.x, center.y + 20), cv::Scalar(0, 0, 255), 4);
    }
    if (winersCounter1 == 2) {
        Point center(610, 10);
        cv::line(in, Point(center.x, center.y), Point(center.x, center.y + 20), cv::Scalar(0, 0, 255), 4);
        cv::line(in, Point(center.x+10, center.y), Point(center.x+10, center.y + 20), cv::Scalar(0, 0, 255), 4);
    }
    if (winersCounter1 == 3) {
        Point center(600, 10);
        cv::line(in, Point(center.x, center.y), Point(center.x, center.y + 20), cv::Scalar(0, 0, 255), 4);
        cv::line(in, Point(center.x+10, center.y), Point(center.x+10, center.y + 20), cv::Scalar(0, 0, 255), 4);
        cv::line(in, Point(center.x+20, center.y), Point(center.x+20, center.y + 20), cv::Scalar(0, 0, 255), 4);
    }
}
void WinP2(Mat& in)
{
    if (winersCounter2 == 1) {
        Point center(40, 10);
        cv::line(in, Point(center.x, center.y), Point(center.x, center.y + 20), cv::Scalar(255, 0, 0), 4);
    }
    if (winersCounter2 == 2) {
        Point center(50, 10);
        cv::line(in, Point(center.x, center.y), Point(center.x, center.y + 20), cv::Scalar(255, 0, 0), 4);
        cv::line(in, Point(center.x-10, center.y), Point(center.x-10, center.y + 20), cv::Scalar(255, 0, 0), 4);
    }
    if (winersCounter2 == 3) {
        Point center(60, 10);
        cv::line(in, Point(center.x, center.y), Point(center.x, center.y + 20), cv::Scalar(255, 0, 0), 4);
        cv::line(in, Point(center.x-10, center.y), Point(center.x-10, center.y + 20), cv::Scalar(255, 0, 0), 4);
        cv::line(in, Point(center.x-20, center.y), Point(center.x-20, center.y + 20), cv::Scalar(255, 0, 0), 4);
    }
}
void Tied(Mat& in)
{
    Point center(300, 200);
    int rad = 20;
    cv::line(in, Point(center.x , center.y-100 ), Point(center.x , center.y+200), cv::Scalar(0, 0, 0), 4);
}
//linea amarilla para el ganador
void DefWin(Mat& in, int w)
{
    Point center(300, 300);
    int rad = 30;
    cv::line(in, Point(center.x+w, center.y - 500), Point(center.x+w, center.y + 200), cv::Scalar(0, 255, 255), 15);
    //waitKey(3000);

}

int main()
{
    cout << "Create video capture!\n";
    string window_name = "video";
    //string window_name2 = "output"; namedWindow(window_name); //resizable window;
    //namedWindow(window_name2); //resizable window;
    Mat frame, frame2;
    //Mat Img_gris(Size(640, 480), CV_8UC1);
    VideoCapture capture(0); for (;;)
    {
        
        capture >> frame2;
        if (frame2.empty()) break;
        Prom (frame2);
        Prom2(frame2);

        //Win1(frame2);
        //Gris(frame2, Img_gris);
        //Gris2(frame2, Img_gris);
        //Win(frame2);

        if (choicePlayer1 == 1 && choicePlayer2 == 1) { Tied(frame2); }
        if (choicePlayer1 == 2 && choicePlayer2 == 2) { Tied(frame2); }
        if (choicePlayer1 == 3 && choicePlayer2 == 3) { Tied(frame2); }
        
        if (choicePlayer1 == 1 && choicePlayer2 == 2 && flag == 1) { winersCounter2++; flag = 0; } //Piedra vs Papel 
        if (choicePlayer1 == 1 && choicePlayer2 == 3 && flag == 1) { winersCounter1++; flag = 0; } //Piedra vs Tijera 
        if (choicePlayer1 == 2 && choicePlayer2 == 1 && flag == 1) { winersCounter1++; flag = 0; } //Papel vs Piedra  
        if (choicePlayer1 == 2 && choicePlayer2 == 3 && flag == 1) { winersCounter2++; flag = 0; } //papel vs Tijera
        if (choicePlayer1 == 3 && choicePlayer2 == 2 && flag == 1) { winersCounter1++; flag = 0; } //Tijera vs Papel
        if (choicePlayer1 == 3 && choicePlayer2 == 1 && flag == 1) { winersCounter2++; flag = 0; } //Tijera vs Piedra
        
        if (winersCounter1 == 1) { WinP1(frame2); }
        if (winersCounter1 == 2) { WinP1(frame2); }
        if (winersCounter1 == 3) { WinP1(frame2); }

        if (winersCounter2 == 1) { WinP2(frame2); }
        if (winersCounter2 == 2) { WinP2(frame2); }
        if (winersCounter2 == 3) { WinP2(frame2); }

        if (winersCounter1 == 3 || winersCounter2 == 3)
        {
            if (winersCounter1 == 3) { DefWin(frame2, 80); }
            else { DefWin(frame2, -40); }
            //waitKey(5000);
            winersCounter1 = 0; winersCounter2 = 0;
        }

        RPS(frame2);
        playersChoice(frame2);
        imshow(window_name, frame2);
        //imshow(window_name2, Img_gris);
        char key = (char)waitKey(5); //delay N millis, usually long enough to display and capture input
        if (key == 'q') { break; }

        if (timeCount > 50) 
        { 
            choicePlayer1 = 0; choicePlayer2 = 0; flag = 1;
        }

        timeCount++;

    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
