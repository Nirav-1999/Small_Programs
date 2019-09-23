import sqlite3
from tkinter import *
from tkinter import messagebox

conn = sqlite3.connect("example.db")
c = conn.cursor()
c.execute("CREATE TABLE IF NOT EXISTS userdata(uname TEXT,pass TEXT)")
INSERT_DATA = "INSERT INTO userdata VALUES(?,?)"
SELECT_USER = "SELECT * FROM userdata WHERE uname=?"
SELECT_DATA = "SELECT * FROM userdata WHERE uname=? and pass=?"

c.execute(INSERT_DATA,('Nirav','nirav'))
conn.commit()
c.execute("SELECT * FROM userdata")
print(c.fetchall())
def login():
    uname = t1.get()
    passwd = t2.get()
    c.execute(SELECT_USER,(uname,))
    if(len(c.fetchall())):
        c.execute(SELECT_DATA,(uname,passwd,))
        if(len(c.fetchall())):
            messagebox.showinfo("Successfull","Logged In!!!")
            root.destroy()
        else:
            messagebox.showwarning("Unsuccessfull","Incorrect Password")
    else:
        messagebox.showwarning("Unsuccessfull","User does not exist")


def register():
    def insert():
        uname = t1.get()
        passwd = t2.get()
        c.execute(INSERT_DATA,(uname,passwd))
        conn.commit()
        messagebox.showinfo("Successfull","User Created")
        reg.destroy()
    root.destroy()
    reg = Tk()
    reg.title("SignUp")
    l1 = Label(reg,text = 'Username')
    l2 = Label(reg,text = 'Password')
    t1 = Entry(reg)
    t2 = Entry(reg, show='*')
    b1 = Button(reg, text='Login', command = insert)
    l1.grid(row = 1, column = 2)
    l2.grid(row = 3, column = 2)
    t1.grid(row = 1, column = 4)
    t2.grid(row = 3, column = 4)
    b1.grid(row = 5, column = 3)
    

root = Tk()
root.title("Login App")
l1 = Label(root,text = 'Username')
l2 = Label(root,text = 'Password')
t1 = Entry(root)
t2 = Entry(root, show='*')
b1 = Button(root, text='Login', command = login)
b2 = Button(root, text='Register', command = register)
l1.grid(row = 1, column = 2)
l2.grid(row = 3, column = 2)
t1.grid(row = 1, column = 4)
t2.grid(row = 3, column = 4)
b1.grid(row = 5, column = 3)
b2.grid(row = 7, column = 3)
root.mainloop()


