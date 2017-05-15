#from datetime import date
import datetime


def datediff(start_date, end_date):
    return abs((end_date-start_date).days)

def main():
    for i in range(5000):
        a = raw_input()
        b = raw_input()
        
        [day, month, year] = map(int, a.split('/'))
        u = datetime.date(year, month, day)
        
        [day, month, year] = map(int, b.split('/'))
        v = datetime.date(year, month, day)
        
        print( datediff(u, v) )
    
main()