/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:35:29 by anthrodr          #+#    #+#             */
/*   Updated: 2024/01/30 09:35:34 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv){

  if (argc > 1){
    for (int j = 1; j < argc; j++){
      size_t length = strlen(argv[j]);
      for(size_t i = 0; i < length; i++){
        argv[j][i] = toupper(argv[j][i]);
        std::cout << argv[j][i];
      }
    }
    std::cout << std::endl;
    return 0;
  }

  std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

  return 0;
}
