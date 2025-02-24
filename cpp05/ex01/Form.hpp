#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        const int _gradeSigned;
        const int _gradeExecute;
        bool _signed;
        //
    public:
        Form();
        Form(const std::string name, const int signedGrade, const int executeGrade) ;
        Form(Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        void beSigned(Bureaucrat Bureaucrat);
        std::string getName() const;
        int getGradeSigned() const;
        int getExecute() const;
        bool getSigned();
        void check(const Form &copy);
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        class GradeNotSigned : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        // exceptions for form to check if the grade if out of bound 
};
std::ostream &operator<<(std::ostream &out,  Form &Form);

#endif