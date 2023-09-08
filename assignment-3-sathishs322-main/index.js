/*
 * Add your JavaScript to this file to complete the assignment.  Don't forget
 * to add your name and @oregonstate email address below.
 *
 * Name:Sabyatha Kumar
 * Email:sathishs@oregonstate.edu
 */


 //access the twit container
 var twitContainer=document.querySelector(".twit-container");

 //creating a new twit and adding to the DOM
 function createTwit(caption, author){
   var newArticle = document.createElement('article');
   newArticle.classList.add('twit')

   var twitIconContainer=document.createElement('div')
   twitIconContainer.classList.add('twit-icon')
   newArticle.appendChild(twitIconContainer)

   var twitIcon=document.createElement('i')
   twitIcon.classList.add('fas')
   twitIcon.classList.add('fa-bullhorn')
   twitIconContainer.appendChild(twitIcon)

   var contentContainer= document.createElement('div')
   contentContainer.classList.add('twit-content')
   newArticle.appendChild(contentContainer)

  
   var contentTextContainer=document.createElement('p')
   contentTextContainer.classList.add('twit-text')
   contentTextContainer.textContent=caption;
   contentContainer.appendChild(contentTextContainer)
   
   var contentAuthorContainer=document.createElement('p')
   contentAuthorContainer.classList.add('twit-author')
   contentAuthorContainer.textContent=author;
   contentContainer.appendChild(contentAuthorContainer) 

   twitContainer.appendChild(newArticle)

   console.log("===newTwit:",newArticle)
   closeTwit()
 }

 //displaying the modal based on clicks
 var modal_drop= document.getElementById("modal-backdrop")
 var create_twit=document.getElementById("create-twit-modal")
 var twitButton=document.getElementById("create-twit-button")
 var close = document.getElementsByClassName("modal-close-button")[0]
 var cancelButton=document.getElementsByClassName("modal-cancel-button")[0]
 var addTwitButton=document.getElementsByClassName("modal-accept-button")[0]

 //add Twit Create button
 twitButton.onclick=function(){
   modal_drop.style.display="block";
   create_twit.style.display="block";
 }


// close the modal when click the x
close.onclick = function() {
  modal_drop.style.display = "none";
  create_twit.style.display="none";
  document.getElementById('twit-text-input').value=''
  document.getElementById('twit-attribution-input').value=''
}

//click cancel button
cancelButton.onclick=function(){
  modal_drop.style.display = "none";
  create_twit.style.display="none"; 
  document.getElementById('twit-text-input').value=''
  document.getElementById('twit-attribution-input').value=''
}


//click the create Twit button
addTwitButton.onclick=function(){
  var text_label= document.getElementById('twit-text-input').value
  var auth_label= document.getElementById('twit-attribution-input').value
 if(text_label==""){
  alert("All your input fields are not filled.")
 }
 else if(auth_label==""){
  alert("All your input fields are not filled.")
 }
 else{
  console.log("===text:",text_label)
  console.log("===auth:",auth_label)
  createTwit(text_label,auth_label)
 }
}

//close the modal
function closeTwit(){
var modal= document.getElementById("modal-backdrop")
 var create=document.getElementById("create-twit-modal")
  modal.style.display = "none";
  create.style.display="none";  
  document.getElementById('twit-text-input').value=''
  document.getElementById('twit-attribution-input').value=''
}

//creating live search 
function searchBar(){
  var input = document.getElementById('navbar-search-input').value
  input=input.toLowerCase();
  var x=document.getElementsByClassName('twit');
  for (i = 0; i < x.length; i++) { 
    if (!x[i].innerText.toLowerCase().includes(input)) {
        x[i].style.display="none";
    }
    else {
        x[i].style.display="list-item";                 
    }
}
}

//when clicking the search buttons
var searchBtn=document.getElementById("navbar-search-button")
var searchInput=document.getElementById("navbar-search-input")
searchBtn.onclick=function(){
  searchBar()
}

searchInput.onkeyup=function(){
  searchBar()
}

