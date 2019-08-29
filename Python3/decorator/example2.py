from functools import wraps


def hello(function):
    @wraps(function)
    def decorator(*args, **kw):
        """
        this is decorator
        test doc
        """
        result = function(*args, **kw)
        return "Hello, {0}".format(result)
    
    return decorator


@hello
def name(arg):
    """my docstring"""
    return arg



print(name("Makina"))
print(name.__name__)
print(name.__doc__)
