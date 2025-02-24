#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(const std::string name, int grade);
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
        void signForm(Form &form); // should check if the form is signed or not
};

std::ostream &operator<<(std::ostream &out,  Bureaucrat &Bureaucrat);

#endif