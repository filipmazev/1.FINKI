const realFileBtn=document.getElementById("file");
const customBtn=document.getElementById("file-button");
const customTxt=document.getElementById("file-text");

customBtn.addEventListener("click", function (){
    realFileBtn.click();
})

realFileBtn.addEventListener("change", function (){
    if (realFileBtn.value){
        customTxt.innerHTML = realFileBtn.value;
    }
    else{
        customTxt.innerHTML = "No file chosen";
    }
})
