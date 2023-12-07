/*
friend function class
inheritence
operator overloading
function overloading
file
stl
template
constructor destructor
*/

#include <raylib.h>
#include "control.h"
#include "blockcolor.h"
#include <bits/stdc++.h>
#include<conio.h>
#include <chrono>
#include <thread>

using namespace std;


int set_speed();
float call();
void akam();

// Function to linearly interpolate between two colors
Color ColorLerp(Color a, Color b, float t)
{
    Color result;
    result.r = (unsigned char)(a.r + (b.r - a.r) * t);
    result.g = (unsigned char)(a.g + (b.g - a.g) * t);
    result.b = (unsigned char)(a.b + (b.b - a.b) * t);
    result.a = (unsigned char)(a.a + (b.a - a.a) * t);
    return result;
}
Color ColorLerp()
{
    Color result;
    result.r = 0;
    result.g =0;
    result.b = 0;
    result.a = 0;
    return result;
}
double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

template<typename T>
T difficulty()
{

    cout<<"1.Easy"<<endl;
    cout<<"2.easy + Medium"<<endl;
    cout<<"3.medium + Hard"<<endl;
    cout<<"4.Hard"<<endl;
    cout<<"5.max Hard"<<endl;

    int choice;
    int k;
    T speed;
    choice=set_speed();

    switch(choice)
    {
    case 1:
        speed = 0.7;
        break;
    case 2:
        speed = 0.5;
        break;
    case 3:
        speed = 0.3;
        break;
    case 4:
        speed = 0.2;
        break;
    case 5:
        speed = 0.1;
        break;
    default:
        break;
    }
    return speed;
}

int password();


const int totalType = 4;
const int totalFlavour = 4;


string arrType[totalType] = {"CONE", "KULFI", "CUP","ROLLED ICE CREAM"};
string arrFlavour[totalFlavour] = {"CHOCOLATE", "VANILA", "MANGO","STRAWBERY"};
int array_price[totalType] = {40, 35, 50,60};

class System;
class Manager;
class Order;
void control(Manager);

class Icecream
{
    string flavour;
    string type;
    int quantity;
    int price;

public:
    Icecream()
    {
        quantity = 0;
    }
    Icecream(string type, string flavour, int quantity, int price)
    {
        this->flavour = flavour;
        this->type = type;
        this->quantity = quantity;
        this->price = price;
    }
    int get_price()
    {
        return price;
    }
    int getTotal_price()
    {
        return price * quantity;
    }
    void display()
    {
if(type=="ROLLED ICE CREAM"&&flavour=="STRAWBERY")
        {
            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t "<< get_price()*quantity<<".00" << endl;
        }
        else if(type=="ROLLED ICE CREAM"&&flavour=="VANILA")
        {

            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t\t"<< quantity<<" x " << get_price() <<"\t\t\t "<< get_price()*quantity<<".00" << endl;
        }
        else if(type=="ROLLED ICE CREAM"&&flavour=="CHOCOLATE")
        {

            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t "<< get_price()*quantity<<".00" << endl;
        }
        else if(type=="ROLLED ICE CREAM"&&flavour=="MANGO")
        {

            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t\t"<< quantity<<" x " << get_price() <<"\t\t\t "<< get_price()*quantity<<".00" << endl;
        }
        else if(type=="CUP"&&flavour=="CHOCOLATE"||type=="CONE"&&flavour=="CHOCOLATE"||type=="KULFI"&&flavour=="CHOCOLATE")
        {

            cout <<"\t\t\t"<< type <<"\t\t\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t "<< get_price()*quantity<<".00" << endl;
        }
        else if(type=="CUP"&&flavour=="STRAWBERY"||type=="CONE"&&flavour=="STRAWBERY"||type=="KULFI"&&flavour=="STRAWBERY")
        {

            cout <<"\t\t\t"<< type <<"\t\t\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t "<< get_price()*quantity<<".00" << endl;
        }
        else
        {
            cout <<"\t\t\t"<< type <<"\t\t\t\t"<< flavour <<"\t\t"<< quantity<<" x " << get_price() <<"\t\t\t "<< get_price()*quantity<<".00" << endl;
        }


    }
    friend class Order;
    friend class Manager;
};

class Order
{
    vector<Icecream> icecream_List;
    string customerName;
    float total;
    string customerNumber;


public:
    Order()
    {

    }

    void add_Icecream(string type, string flavour, int quantity, int price)
    {
        icecream_List.push_back(Icecream(type, flavour, quantity, price));
        cout << "\t\tSUCCESSFULLY ADDED" << endl;
    }
    void setName(string name)
    {
        this->customerName = name;
    }
    void setNumber(string customerNumber)
    {
        this->customerNumber=customerNumber;
    }
    void recipt()
    {
        float dis=call();
       total = 0;
        cout<<endl<<endl<<"\t\t\t\t\t\t       GELATO GALORE"<<endl;
        cout<<endl<<"\t\t\t\t\t         SWC - 1 KUET RD, KHULNA"<<endl;
        cout<<"\t\t\t\t\t           TEL : 019XX -XXX-XXX"<<endl<<endl;
        cout<<"\t\t\t--------------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<endl<<"\t\t\t\t\t\t       ORDER RECIPT "<<endl;
        cout<<"\t\t\t--------------------------------------------------------------------------------"<<endl<<endl;;
        cout<<"\t\t\tNAME           : "<<customerName<<endl<<endl;
        cout<<"\t\t\tMOBILE NUMBER  : "<<customerNumber<<endl<<endl;
        cout<<"\t\t\tORDERS --"<<endl<<endl;
        cout<<"\t\t\tTYPE\t\t\t\tFLAVOUR\t\tQUANTITY\t\tcost"<<endl<<endl<<endl;
        for (Icecream i : icecream_List)
        {
            i.display();
            total += i.getTotal_price();
        }
        cout <<endl<<endl<<"\t\t\tVAT"<<"\t\t\t\t"<<"\t\t"<<"   "<<"\t\t\t 15%"<< endl;
        cout <<endl<<endl<<"\t\t\tDISCOUNT"<<"\t\t\t\t"<<"\t\t"<<"   "<<"\t\t "<<dis<<".00"<< endl;
        cout<<endl<<endl;
        cout<<"\t\t\t--------------------------------------------------------------------------------"<<endl;

        cout<<"\t        \t\tTOTAL   \t\t\t\t\t\t\t= "<<total+total*0.15-dis<<endl;

    }
    friend class Manager;
    friend float call();
};

class Manager
{
    vector<Order> survey;
    int arrQuantity[totalType][totalType] = {};
    int choice_speed;

public:
    Manager() { }
    void total_income()
    {
        int total_income = 0;
        for (int type = 0; type < totalType; type++)
        {
            for (int flavour = 0; flavour < totalFlavour; flavour++)
            {
                total_income += arrQuantity[type][flavour] * array_price[type];
            }
        }
        cout << "\t     TOTAL REVENUE GENERATED : " << total_income << endl;
    }
    void saveOrder(Order ord)
    {
        for (Icecream ice : ord.icecream_List)
        {
            int type, flavour;
            for (type = 0; type < totalType; type++)
            {
                if (ice.type == arrType[type])
                    break;
            }
            for (flavour = 0; flavour < totalFlavour; flavour++)
            {
                if (ice.flavour == arrFlavour[flavour])
                    break;
            }
            arrQuantity[type][flavour] += ice.quantity;
        }
    }
    void show_product_sells()
    {
        cout <<endl<<"\t\t\t----------PRODUCT DETAILS WITH REVENUE ----------"<<endl<<endl;
        int type, flavour;
        for (type = 0; type < totalType; type++)
        {
            cout << endl<<"\t\tTYPE : " << arrType[type] << endl;
            for (flavour = 0; flavour < totalFlavour; flavour++)
            {
                cout <<endl<< "\t\t - FLAVOUR : " << arrFlavour[flavour] << "\tQUANTITY : " << arrQuantity[type][flavour] ;
                cout << "\tREVENUE : " << arrQuantity[type][flavour] * array_price[type] << "\n";
            }
        }
    }


    friend istream& operator>>(istream& input, Manager& choice)
    {
        cout << "Enter choice : ";
        input >> choice.choice_speed;
        return input;
    }

    friend ostream& operator<<(ostream& output, Manager& choice)
    {
        output << "The saved integer is: " << choice.choice_speed << endl;
        return output;
    }

    void saveSpedToFile(const string& filename,Manager ch)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << ch.choice_speed;
            file.close();
            cout << "speed saved to system " << "TetraStsck" << endl;
        }
        else
        {
            cout << "Unable to open the file for writing." << endl;
        }
    }
    friend int set_speed();
};
int set_speed()
{
    Manager s;
    int t=s.choice_speed;
    return t;
}
class System
{
    Order ord;
    string name;
    string mobile_no;
public:
    System()
    {
    }
    void menu(Manager &mn)
    {
        cout <<endl<< "\t\tENTER NAME :  ";
        getline(cin,name);
        ord.setName(name);
        cout <<endl<< "\t\tENTER MOBILE NUMBER :  ";
        getline(cin,mobile_no);
        ord.setNumber(mobile_no);

        char s, d;
        cout <<endl<< "\t\t   ---- OUR PRODUCTS ----\n"<<endl;
        for(int i = 0; i<totalType; i++)
        {
            if(arrType[i]=="ROLLED ICE CREAM")
                cout <<"\t\t"<< i+1 << ". " << arrType[i] <<"\tPRICE: " << array_price[i] << "\n";
            else if(arrType[i]=="KULFI")
                cout <<"\t\t"<< i+1 << ". " << arrType[i] <<"\t\tPRICE: " << array_price[i] << "\n";
            else
                cout <<"\t\t"<< i+1 << ". " << arrType[i] <<"\t\t\tPRICE: " << array_price[i] << "\n";

        }
        cout <<endl<< "\t\t   ---- AVAILABLE FLAVOURS ----"<<endl<<endl;
        for(int i = 0; i<totalFlavour; i++)
        {
            cout <<"\t\t"<< i+1 << ". " << arrFlavour[i] << "\n";

        }
        do
        {
            takeOrder();
            cout <<endl<< "\t\tWOULD YOU LIKE TO ORDER AGAIN .";
            cout<<endl<<"\t\tIF YES PRESS (y/Y) OR PRESS (N/n) :";
            cin >> s;
            cout<<endl;
        }

        while (s == 'y' || s == 'Y');

        cout<<"\t\t\t PLAY GAME TO GET A WONDERFUL DISCOUNT"<<endl;

        cout<<"\t\t\t..........."<<endl;
        //a processing delay
        this_thread::sleep_for(std::chrono::seconds(3));
        akam();

        system("cls");
        cout << "\t\t\tPROCESSING YOUR REQUEST...\n";

        //a processing delay
        this_thread::sleep_for(std::chrono::seconds(3));

        cout << "\t\t\tPRINTING RECIPT...\n";

        // another delay for receipt printing
        this_thread::sleep_for(chrono::seconds(2));

        cout << "\t\t\tRECIPT PRINTED SUCCESSFULLY!\n";
        ord.recipt();
        mn.saveOrder(ord);
        cout << endl<<endl<<"\t\t ENTER ANY KEY TO EXIT : ";
        cin >> d;
    }
    void takeOrder()
    {
        cout<<endl;
        int command_type, command_flavour, command_quantity;
        for(int i = 0; i<totalFlavour; i++)
        {
            cout <<"\t\t\tPRESS "<<i+1 << " FOR " << arrFlavour[i] <<" FAVORES "<<endl;

        }
        cout <<endl<< "\t\tENTER YOU FAVOURITE FLAVOUR : ";
        cin >> command_flavour;
        cout<<endl;
        for(int i = 0; i<totalFlavour; i++)
        {
            cout <<"\t\t\tPRESS "<<i+1 << " FOR " << arrType[i] <<" TYPES "<<endl;
        }
        cout <<endl<<  "\t\tENTER YOU FAVOURITE TYPE : ";
        cin >> command_type;
        cout<<endl;
        cout <<endl<<  "\t\tENTER QUANTITY : ";
        cin >> command_quantity;
        ord.add_Icecream(arrType[command_type - 1], arrFlavour[command_flavour - 1], command_quantity, array_price[command_type - 1]);
    }
    friend class Manager;
    friend void control();
};

int main()
{

    Manager b;
    char k;
    while (true)
    {
        char s;
        cout<<endl<<"\t\t\t\t\tWELCOME TO GELATO GALORE"<<endl<<endl;
        this_thread::sleep_for(std::chrono::seconds(3));
        cout<<endl<<"\t\t\t\tAN ICE-CREAM VENDING MACHINE FOR KUETIANS"<<endl<<endl<<endl;
        this_thread::sleep_for(std::chrono::seconds(2));

        cout << "\t\tARE YOU A STUDENT ???" << endl<<endl;
        cout << "\t\tIF YES PTRESS (Y/y) else PRESS (n/N) : ";
        cin >> s;
        cin.ignore();
        if (s == 'y'||s == 'Y')
        {
            System x;
            x.menu(b);
        }
        else if (s == 'n'||s == 'N')
        {
            cout<<"\t\t ENTER PASSWORD : ";
            if(password()==1)
            {
                cout <<endl<<endl<<"\t\t\tWELCOME TO GELATO GALOREE CONTROL PANNEL " << endl<<endl;
                cout<<endl<<"\t    PRESS 1 TO SEE TOTAL REVENUE"<<endl;
                cout<<"\t    PRESS 2 TO SEE SOLD PRODUCTS WITH QUANTITY"<<endl;
                cout<<"\t    PRESS 3 TO SEE ENHANCE GAME SPEED"<<endl;
                cout<<"\t    ENTER : ";
                cin>>s;
                if(s=='1')
                {
                    b.total_income();
                }
                else if(s=='2')
                {
                    b.show_product_sells();
                }
                //saveSpedToFile
                else if(s=='3')
                {
                    cin>>b;
                    cout<<b;

                    b.saveSpedToFile("choice.txt",b);
                }
                do
                {
                    this_thread::sleep_for(std::chrono::seconds(2));
                    cout<<endl<<endl<<"\t\t\t\t WOULD YOU LIKE TO CHECK AGAIN ? "<<endl;
                    cout<<endl<<endl<<"\t\t\t\t IF YES PRESS(y/Y) OR PRESS(N/n)  :  ";
                    cin>>s;
                    if(s=='y')
                        control(b);
                }
                while(s=='y'&&s!='n');
            }
            else
                cout<<"\t  WRONG PASSWORD ! \n TRY FROM BEGINNING"<<endl;
        }
        if (s == 'y'||s == 'Y')
        {
            system("cls");
            cout<<endl<<endl<<"\t\t\t-----------THANKS FOR USING KUET VENDING MACHINE-----------"<<endl<<endl;
            cout<<"\t\t\t\t         HAVE A NICE DAY  !!!! "<<endl;
        }
        cout <<endl<< "\t\t\t ENTER ANY KEY TO EXIT : ";
        cin >> k;
        system("cls");
    }
    return 0;
}
void control(Manager b)
{
    char s;
    cout<<" \t    PRESS 1 TO SEE TOTAL REVENUE"<<endl;
    cout<<" \t    PRESS 2 TO SEE SOLD PRODUCTS WITH QUANTITY"<<endl<<endl;
    cout<<" \t    ENTER : ";
    cin>>s;

    if(s=='1')
    {
        b.total_income();
    }
    else if(s=='2')
    {
        b.show_product_sells();
    }
    else if(s=='3')
    {
        cin>>b;
        cout<<b;

        b.saveSpedToFile("choice.txt",b);
    }
}
int password()
{
    const string correctPassword = "one";
    string enteredPassword;
    char ch;
    while ((ch = _getch()) != 13)
    {
        if (ch == 8)
        {
            if (!enteredPassword.empty())
            {
                enteredPassword.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            enteredPassword.push_back(ch);
            cout << '*';
        }
    }

    cout << endl;

    if (enteredPassword == correctPassword)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void akam()
{
    //float speed = 0.3;
    float speed=difficulty<float>();
    const int screenWidth = 980;
    const int screenHeight = 950;

    InitWindow(screenWidth, screenHeight, "TetraTeris");
    SetTargetFPS(60);

    Color startColor = {0, 0, 0, 255};
    Color endColor = {0, 0, 40, 255};

    const int numStars = 100;
    Vector2 stars[numStars];
    Color starColor = RAYWHITE;
    for (int i = 0; i < numStars; i++)
    {
        stars[i].x = (float)(rand() % screenWidth);
        stars[i].y = (float)(rand() % screenHeight);
    }

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Texture2D atlas = LoadTexture("IMAGES/Game-Over-PNG-Image.png");

    Game game = Game();

    while (WindowShouldClose()==false)
    {

        BeginDrawing();


        // Clear the screen with the gradient background
        for (int y = 0; y < screenHeight; y++)
        {
            Color lerpedColor = ColorLerp(startColor, endColor, (float)y / screenHeight);
            DrawRectangle(0, y, screenWidth, 1, lerpedColor);
        }

        // Draw stars
        for (int i = 0; i < numStars; i++)
        {
            DrawPixelV(stars[i], starColor);

            // Simulate twinkling stars by changing their color randomly
            if (GetRandomValue(0, 100) < 2)
            {
                starColor = (Color)
                {
                    GetRandomValue(200, 255), GetRandomValue(200, 255), GetRandomValue(200, 255), 255
                };
            }
        }
        UpdateMusicStream(game.music);
        game.HandleInput();
        speed=0.09;
        if (EventTriggered(speed))
        {
            game.MoveBlockDown();
        }

        DrawTextEx(font, "SCORE", {650, 70}, 85, 4, RED);
        DrawTextEx(font, "Next", {650, 285}, 85, 2, YELLOW);
        if (game.gameOver)
        {
            PauseMusicStream(game.music);
            DrawTextureEx(atlas,(Vector2)
            {
                600, 685
            },0,0.6f,WHITE);
        }
        DrawRectangleRounded({650, 155, 260, 100}, 0.3, 6, darkblue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 75, 2);


        DrawTextEx(font, scoreText, {710 + (170 - textSize.x) / 2, 175}, 75, 2, WHITE);
        DrawRectangleRounded({650, 400, 170, 180}, 0.3, 6, darkblue);
        game.Draw();
        EndDrawing();


    }
    //cout<<game.score<<endl;
    ofstream outputFile("integer.txt");
    if (!outputFile.is_open())
    {
        cout << "Error: Failed to open the file " << endl;
        // return;
    }
    int value = game.score;
    outputFile << value;
    outputFile.close();


    CloseWindow();
}

float call()
{
    float discount;
    ifstream inputFile("integer.txt");

    // Check if the file was opened successfully
    if (!inputFile.is_open())
    {}

    // Read the integer value from the file
    if (!(inputFile >> discount))
    {
    }
// Close the file
    inputFile.close();
    return discount;
}
