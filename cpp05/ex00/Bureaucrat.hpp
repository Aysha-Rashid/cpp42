#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat();
        Bureaucrat(Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        const std::string getName(void);
        int getGrade(void);
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };
        void increment(void);
        void decrement(void);
        void CheckHighOrLow(int grade);
};
std::ostream &operator<<(std::ostream &out,  Bureaucrat &Bureaucrat);

#endif