#include <iostream>
#include <vector>

using namespace std;

class Handler {
 public:
  virtual Handler *SetNext(Handler *handler) = 0;
  virtual std::string Handle(std::string request) = 0;
};

class AbstractHandler : public Handler {

 private:
  Handler *next_handler_;

 public:
  AbstractHandler() : next_handler_(nullptr) {
  }
  //This function will let us st the next handler which is going to take care
  Handler *SetNext(Handler *handler) override {
    this->next_handler_ = handler;
    return handler;
  }
  std::string Handle(std::string request) override {
    if (this->next_handler_) {
      return this->next_handler_->Handle(request);
    }

    return {};
  }
};

class Dispatch100 : public AbstractHandler {
 public:
  std::string Handle(std::string request) override {
    if (request == "100") {
      return "ObjOf100: I'll handle the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};
class Dispatch500 : public AbstractHandler {
 public:
  std::string Handle(std::string request) override {
    if (request == "500") {
      return "ObjOf500: I'll handle the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};
class Dispatch2000 : public AbstractHandler {
 public:
  std::string Handle(std::string request) override {
    if (request == "2000") {
      return "ObjOf2000: I'll handle the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};


// Client Side cose 

void ClientCode(Handler &handler) {
  std::vector<std::string> food = {"100", "500", "2000"};
  for (const std::string &f : food) {
    std::cout << "Client: Who wants a " << f << "?\n";
    const std::string result = handler.Handle(f);
    if (!result.empty()) {
      std::cout << "  " << result;
    } else {
      std::cout << "  " << f << " was left untouched.\n";
    }
  }
}

int main() {
  Dispatch100 *ObjOf100 = new Dispatch100;
  Dispatch500 *ObjOf500 = new Dispatch500;
  Dispatch2000 *ObjOf2000 = new Dispatch2000;
  ObjOf100->SetNext(ObjOf500)->SetNext(ObjOf2000);

  /**
   * The client should be able to send a request to any handler, not just the
   * first one in the chain.
   */
  std::cout << "Chain: ObjOf100 > ObjOf500 > ObjOf2000\n\n";
  ClientCode(*ObjOf100);
  std::cout << "\n";
  std::cout << "Subchain: ObjOf500 > ObjOf2000\n\n";
  ClientCode(*ObjOf500);

  delete ObjOf100;
  delete ObjOf500;
  delete ObjOf2000;

  return 0;
}
