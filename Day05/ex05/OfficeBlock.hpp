/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:31:14 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:35:51 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef OFFICEBLOCK_CLASS_H
# define OFFICEBLOCK_CLASS_H

# include <stdexcept>
# include <string>
# include <iostream>

# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock
{
	public:
		class InvalidEntityException : public std::exception {
			public:
				InvalidEntityException(void);
				InvalidEntityException(InvalidEntityException const &obj);
				~InvalidEntityException(void) throw();

				InvalidEntityException &operator=(InvalidEntityException const &rhs);

				const char *what(void) const throw();
		};

		class NoInternException : public std::exception {
			public:
				NoInternException(void);
				NoInternException(NoInternException const &obj);
				~NoInternException(void) throw();

				NoInternException &operator=(NoInternException const &rhs);

				const char *what(void) const throw();
		};

		class NoExecutorException : public std::exception {
			public:
				NoExecutorException(void);
				NoExecutorException(NoExecutorException const &obj);
				~NoExecutorException(void) throw();

				NoExecutorException &operator=(NoExecutorException const &rhs);

				const char *what(void) const throw();
		};

		class NoSignerException : public std::exception {
			public:
				NoSignerException(void);
				NoSignerException(NoSignerException const &obj);
				~NoSignerException(void) throw();

				NoSignerException &operator=(NoSignerException const &rhs);

				const char *what(void) const throw();
		};

		OfficeBlock(void);
		OfficeBlock(Intern *i, Bureaucrat *signer, Bureaucrat *executor);
		~OfficeBlock(void);

		Intern *getIntern(void) const;
		Bureaucrat *getSigner(void) const;
		Bureaucrat *getExecutor(void) const;

		void setIntern(Intern *intern);
		void setSigner(Bureaucrat *signer);
		void setExecutor(Bureaucrat *executor);

		void doBureaucracy(std::string type, std::string target);
	private:
		Intern		*_intern;
		Bureaucrat	*_signer;
		Bureaucrat	*_executor;
};

#endif
