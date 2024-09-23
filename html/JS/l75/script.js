// javascript callbacks and promises

console.log("this is promises")

let prom1= new Promise((resolve,reject)=>{

    let a =Math.random();
    if(a>0.5){
        reject("not valid")
    }else{
        setTimeout(()=>{
            console.log("this is valid") 
        },2000)
    }
})

prom1.then((a)=>{
    console.log(a)
}).catch((err)=>{
    console.log(err)
})