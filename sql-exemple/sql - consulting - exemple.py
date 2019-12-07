import mysql.connector
con = mysql.connector.connect(user='root', password='your-password', host='127.0.0.1',database='your-database')
cursor = con.cursor()
consulting = "select column1,column2,column3 from yellowpage where id > 5"
cursor.execute(consulting)
for (column1,column2,column3) in cursor:
    print(f'nome: {column1}, tel: {column2}, cel: {column3}')
cursor.close()
con.close