//
// Created by CiaranWelsh on 09/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_LOG_H
#define POKERSIMULATIONSINCPP_LOG_H
#define LOG(msg, ...) \
    std::cout <<__FILE__ << ":" << __LINE__ << ": "<< msg << std::endl;

#endif //POKERSIMULATIONSINCPP_LOG_H
