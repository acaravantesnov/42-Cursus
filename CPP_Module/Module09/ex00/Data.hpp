#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data
{
    private:
        std::string	_date;
        float		_value;
    public:
        Data();
        Data(const std::string date, const float value);
        ~Data();
        Data &operator=(Data &data);

        std::string   getDate() const;
        void          setDate(std::string date);
        float         getValue() const;
        void          setValue(float value);
};

#endif
