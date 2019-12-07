import mysql.connector
con = mysql.connector.connect(user='root', password='your-password',host='127.0.0.1',database='your-database')
cursor = con.cursor()
print('insert first column:\n')
info1 = input()
print('insert second column:\n')
info2 = input()
print('insert third column:\n')
info3 = input()
inserir = f"insert into table-name (first-column, second-column, third-column) values ('{info1}', '{info2}', '{info3}')"
cursor.execute(inserir)
con.commit()
cursor.close()
con.close