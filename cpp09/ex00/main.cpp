#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>


void test(std::map<std::string, float> const & exchange_rates, std::string const & date, float const & val)
{
    try
    {
        float ex_rate = exchange_rates.at(date);
        std::cout << "Exchange rate for " << date << ": " << ex_rate * val << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exchange rate for " << date << ": " << (--exchange_rates.lower_bound(date))->second * val << std::endl;
    }
}

void initialize_database(std::map<std::string, float> & exchange_rates)
{
    std::ifstream infile("data.csv");
    float rate;
    std::istringstream in;
    std::string date_str, line;
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        line.replace(10, 1, " ");
        in.str(line);
        in >> date_str >> rate;
        in.clear();
        exchange_rates[date_str] = rate;
    }
}

bool validate_date(std::string const & date)
{
    std::istringstream in(date);
    std::string chk;
    int year, month, day;
    char delimiter;

    if (in >> year >> delimiter >> month >> delimiter >> day) {
        if (in.fail() || delimiter != '-' || in >> chk) {
            return false;
        }
        if (year < 2009 || year > 9999) {
            return false;
        }
        if (month < 1 || month > 12) {
            return false;
        }
        if (day < 1 || day > 31) {
            return false;
        }
        return true;
    }

    return false;
}

bool validate(std::string const & date, char const & delim, float const & value, std::string const & line)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    if (!validate_date(date) || delim != '|')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    return true;
}

void parse_file(std::string const & filename, std::map<std::string, float> const & exchange_rates)
{
    std::string date_str, line, chk;
    float value;
    std::string::size_type pos;
    std::istringstream in;
    char delim;
    std::ifstream infile(filename.c_str());
    
    if (!infile || infile.fail()) {
        std::cerr << "Error: failed to open file " << filename << std::endl;
        return ;
    }
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        pos = line.find(',');
        if (pos != std::string::npos)
            line.replace(pos, 1, ".", 1);
        in.str(line);
        in >> date_str >> delim >> value;
        if (!in.fail() && !(in >> chk))
        {
            if (validate(date_str, delim, value, line))
                test(exchange_rates, date_str, value);
        }
        else
            std::cout << "Error: bad input => " << line << std::endl;
        in.clear();
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "wrong number of arguments" << std::endl;
        return (1);
    }

    std::map<std::string, float> exchange_rates;
    initialize_database(exchange_rates);
    //parse the input.txt
    parse_file(av[1], exchange_rates);

    return (0);
}
