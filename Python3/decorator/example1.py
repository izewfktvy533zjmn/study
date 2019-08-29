def decorator(func):
    def wrapper(*args, **kwargs):
        print("--start--")
        ret = func(*args, **kwargs)
        print("--end--")

        return ret

    return wrapper


def deco(arg):
    def decorator(func):
        def wrapper(*args, **kwargs):
            print(args)
            print(kwargs)
            print(arg)
            ret = func(*args, **kwargs)
            
            return ret
         
        return wrapper
    
    return decorator
         

@deco("test")
def test():
    print("Hello, Decorator")
    return "makina"


def test1():
    print("This is test1 function.")
    return "test1 function"


print(test())


print()


tmp = deco("test1")
tmp = tmp(test1)
print(tmp())

