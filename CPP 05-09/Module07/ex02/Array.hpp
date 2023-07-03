/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:18:27 by jaromero          #+#    #+#             */
/*   Updated: 2023/07/01 12:55:05 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T = int>

class Array
{
    private:
        unsigned int    _size;
        T*              _array;
        
    public:
        Array<T>(void)
        {
            this->_size = 0;
            this->_array = NULL;
        };
        
        Array<T>(unsigned int n)
        {
            this->_size = n;
            this->_array = new T[_size]();
        };

        Array<T>(Array<T> const &copy)
        {
            int i;

            i = 0;
            this->_size = copy._size;
            this->_array = new T[this->_size]();
            while (copy._array[i])
            {
                this->_array[i] = copy._array[i];
                i++;
            }
        };
        
        ~Array<T>(void)
        {
            delete [] _array;
        };

        Array<T>&   operator=(Array<T> const &pointer)
        {
            int i;
            
            i = 0;
            this->_size = pointer._size;
            this->_array = new T[this->_size]();
            while (pointer._array[i])
            {
                this->_array[i] = pointer._array[i];
                i++;
            }
            return (*this);
        };

        T&  operator[](size_t index)
        {
            if (index < 0 || index >= this->_size)
			    throw InvalidIndexException("Error, invalid index!\n");
            return (this->_array[index]);
        };

        unsigned int    size(void)
        {
            return (this->_size);
        };

        class InvalidIndexException : public std::exception
        {
            private:
                std::string _strerror;
            public:
                InvalidIndexException(const std::string& str) : _strerror(str) {}
                virtual ~InvalidIndexException() _NOEXCEPT {}  
                const char* what() const _NOEXCEPT { return _strerror.c_str(); }
        };
};

#endif