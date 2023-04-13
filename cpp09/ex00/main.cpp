#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <regex>


void test (std::map<std::string, float> exchange_rates)
{
    std::string date_to_lookup = "2012-03-17";
    if (exchange_rates.count(date_to_lookup))
    {
        std::cout << "Exchange rate for " << date_to_lookup << ": " << exchange_rates[date_to_lookup] << std::endl;
    }
    else
    {
        std::cout << "No exchange rate data available for " << date_to_lookup << std::endl;
    }

}

void initialize_database(std::map<std::string, float> &exchange_rates)
{
    std::ifstream infile("data.csv");
    float rate;
    std::string date_str, rate_str, line;
    std::string::size_type delimiter_pos;
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        delimiter_pos = line.find(',');
        date_str = line.substr(0, delimiter_pos);
        rate_str = line.substr(delimiter_pos + 1);
        rate = std::stof(rate_str);
        exchange_rates[date_str] = rate;
    }
}

bool is_valid_float(std::string& str) {
    float value;
    static const std::regex float_pattern("^[ -+]?([0-9]*\\.[0-9]+|[0-9]+)");

    if (str.find(',') != std::string::npos)
        str.replace(str.find(','), 1, ".");
    if (str.find('.') != std::string::npos && !std::regex_match(str, float_pattern))
        return false ;
    try
    {
        value = std::stof(str);
        if(value > 1000 || value < 0)
            return false ;
    }
    catch(std::exception &f)
    {
        return false ;
    }
    return true;
}

bool is_valid_date(const std::string& str) {
    std::string d_start("2009-01-02"), d_end("2022-03-29");
    static const std::regex float_pattern("^(((19|20)([2468][048]|[13579][26]|0[48])|2000)[-]02[-]29|((19|20)[0-9]{2}[-](0[4678]|1[02])[-](0[1-9]|[12][0-9]|30)|(19|20)[0-9]{2}[-](0[1359]|11)[-](0[1-9]|[12][0-9]|3[01])|(19|20)[0-9]{2}[-]02[-](0[1-9]|1[0-9]|2[0-8])))[ ]$");
    return (str > d_end || str < d_start || std::regex_match(str, float_pattern));
}

void parse_file(std::string filename)
{
    std::string date_str, value_str, line;
    std::string::size_type delimiter_pos;
    std::ifstream infile(filename);
    
    if (!infile || infile.fail()) {
        std::cerr << "Error: failed to open file " << filename << std::endl;
        return ;
    }
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        delimiter_pos = line.find('|');
        if(delimiter_pos == std::string::npos)
            continue ;
        date_str = line.substr(0, delimiter_pos);
        value_str = line.substr(delimiter_pos + 1);
        if(!is_valid_float(value_str))
            continue ;
        if (!is_valid_date(date_str))
            continue ;
        std::cout << date_str << "|" << value_str << std::endl;
        // std::cout << value << std::endl;
    }
}

int main(int ac, char **av)
{
    std::map<std::string, float> exchange_rates;
    initialize_database(exchange_rates);
    //parse the input.txt
    if (ac != 2)
    {
        std::cerr << "wrong number of arguments" << std::endl;
        return (1);
    }
    parse_file(av[1]);
    // test(exchange_rates);

    return (0);
}