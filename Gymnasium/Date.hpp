#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

class Date
{
protected:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
public:
    static char* GetCurrentDate()
    {
            auto start = std::chrono::system_clock::now();
            time_t time = chrono::system_clock::to_time_t(start);
            return ctime(&time);
    }

    Date(char* ctimeDateString)
    {
        char month1[4];
        sscanf(ctimeDateString,"%*s%s%d%d%*c%d%*c%d%d", month1,&day,&hours,&minutes,&seconds,&year);
        for(int i = 0; i <= 12; i++)
        {
            if(strcmp(months[i], month1) == 0)
            {
                this->month = i + 1;
                break;
            }
        }
    }
};



#endif // DATE_HPP_INCLUDED
