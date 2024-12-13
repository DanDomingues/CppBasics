#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct City
{
    string name;
    long population;
    double cost;
};

struct Country
{
    string name;
    vector<City> cities;
};

struct Tours
{
    string title;
    vector<Country> countries;
};

const int full_width {65};
const int country_width {full_width * 1/5};
const int city_width {full_width * 2/5};
const int population_width {full_width * 1/5};
const int price_width {full_width * 1/5};


Tours get_tours(string initial_city)
{
    return Tours
    {
        "Tour Ticket Prices from " + initial_city,
        {
        {
                "Colombia",
                {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 24001000, 424.21 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 },
                }
            },
            {
                "Brazil",
                {
                    { "Rio de Janeiro", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 },
                }
            },
            {
                "Chile",
                {
                    { "Validivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 },
                }
            },
            {
                "Argentina",
                {
                    { "Buenos Aires", 3010000, 728.77 },
                }
            },
        }
    };
}

string format_population(long value)
{
    auto input = to_string(value);

    string output;
    int counter {1};
    for(int i {(int) input.length() - 1}; i >= 0; i--)
    {
        auto c = input.at(i);
        output.insert(output.begin(), c);
        
        if(i == 0)
        {
            continue;
        }
        
        if(counter > 0 && counter % 3 == 0)
        {
            output.insert(output.begin(), '.');
        }
        counter++;
    }
    return output;
}

string format_price(double value)
{
    auto s = to_string(value);
    bool is_decimal {false};
    int decimal_cases {2};
    int counter {0};
    string s_o;

    for(auto c:s)
    {
        if(is_decimal)
        {
            counter++;
            if(counter > decimal_cases)
            {
                break;
            }
        }

        if(c == '.')
        {
            is_decimal = true;
        }

        s_o += c;
    }

    return s_o + "$";
}

void output_city(string country_name, City city)
{   
    cout.precision(2);
    cout << /*setfill('*') <<*/ setw(country_width) << left << country_name;
    cout << /*setfill('-') <<*/ setw(city_width) /*<< left*/ << city.name;
    cout << /*setfill('+') <<*/ setw(population_width) << right <<  format_population(city.population);
    cout << /*setfill('=') <<*/ setw(price_width) /*<< right << "$"*/ << fixed << format_price(city.cost) << endl;
}

void output_country(Country country)
{
    int i {0};
    string header;
    for(auto city:country.cities)
    {
        header = i == 0 ? country.name : "";
        output_city(header, city);
        i++;
    }
    cout << "\n";
}

void draw_title(string title)
{
    int mid_point = full_width / 2;
    int right_pivot = mid_point + (title.length() / 2);
    int offset = full_width * 1/50 * -1; //-2% offset
    cout << setw(right_pivot + offset) << right << title << "\n\n";
}

void draw_header()
{
    cout << setw(country_width) << left << "Country";
    cout << setw(city_width) /*<< left*/ << "City";
    cout << setw(population_width) << right << "Population";
    cout << setw(price_width) /*<< right*/ << "Price";
    cout << "\n";
    cout << string(full_width, '-') << endl;
}

int main(int argc, char const *argv[])
{   
    cout << string(5, '\n');
    
    auto tours = get_tours("Tokyo");
    draw_title(tours.title);
    draw_header();

    for(auto coutry:tours.countries)
    {
        output_country(coutry);
    }

    cout << string(5, '\n');
    return 0;
}

//Notes
//io mods must be set *before* the affected input
