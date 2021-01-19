//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_ISUBJECT_H
#define POKERSIMULATIONSINCPP_ISUBJECT_H

#include "Observer.h"

class ISubject {
 public:
  virtual ~ISubject()= default;;
  virtual void attach(CardCollectionObserver *observer) = 0;
  virtual void detach(CardCollectionObserver *observer) = 0;
  virtual void notify() = 0;
};

#endif //POKERSIMULATIONSINCPP_ISUBJECT_H
