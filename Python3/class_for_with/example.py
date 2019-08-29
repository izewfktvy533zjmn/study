class WithClass:
    def __init__(self):
        print("init")


    def __enter__(self):
        print("enter")
        
        return self


    def __exit__(self, exception_type, exception_value, traceback):
        print("exit:", exception_type, exception_value, traceback)

    
    def func(self):
        print("test")
        print(1/0)


with WithClass() as wc:
    wc.func()
