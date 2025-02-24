#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const int _gradeSigned;
        const int _gradeExecute;
        bool _signed;

    public:
        AForm();
        AForm(const std::string name, const int signedGrade, const int executeGrade) ;
        AForm(AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        void beSigned(const Bureaucrat &Bureaucrat);
        std::string getName() const;
        int getGradeSigned() const;
        int getExecute() const;
        bool getSigned() const;
        void check(const AForm &copy);
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
        
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out,  AForm &Form);

#endif