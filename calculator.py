from tkinter import *
def press(key):
    if key=="=":
        try:
            display.set(eval(display.get()))
        except:
            display.set("Error")
    elif key=="C":
        display.set("")
    else:
        display.set(display.get()+key)
root=Tk()
root.title("Calculator")
root.geometry("300x350",bg="black")
display=StringVar()
Entry(root,textvariable=display,font=("Arial",18),justify="right").grid(row=0,column=0,columnspan=4,padx=10,pady=10)
buttons=['7','8','9','/','4','5','6','*','1','2','3','-','0','.','=','+']
r,c=1,0
for b in buttons:
    Button(root,text=b,width=5,height=2,bg="red",command=lambda x=b: press(x)).grid(row=r,column=c,padx=5,pady=5)
    c+=1
    if c==4:
        c=0
        r+=1
Button(root,text='C',width=22,height=2,command=lambda: press("C")).grid(row=r,column=0,columnspan=4,pady=5)
root.mainloop()
