const humidity = document.querySelector('.humidityValue');
const temperature = document.querySelector('.tempValue');
const light = document.querySelector('.luxValue');
const weatherImage = document.querySelector('.weatherImageHolder');

function updateValue(data1,data2,data3) {
  humidity.innerHTML = data1;
  temperature.innerHTML = data2;
  light.innerHTML = data3;

  if (light.innerHTML < 300) {
    weatherImage.innerHTML = `<img class="weatherImage" src="./images/moon.png" alt="moon"></img>`;
  } else if (humidity.innerHTML > 70 && temperature.innerHTML > 34) {
    weatherImage.innerHTML = `<img class="weatherImage" src="./images/storm.png" alt="storm"></img>`;
  } else {
    weatherImage.innerHTML = `<img class="weatherImage" src="./images/sunny.png" alt="sunny">`;
  }
}

var database = firebase.database();
var dataRef1 = database.ref("humidity");
var dataRef2 = database.ref("temp");
var dataRef3 = database.ref("light")

var data1;
var data2;
var data3;

dataRef1.on("value", function(snapshot) {
  data1 = snapshot.val();
});

dataRef2.on("value", function(snapshot) {
  data2 = snapshot.val();
});

dataRef3.on("value", function(snapshot) {
  data3 = snapshot.val();
  updateValue(data1,data2,data3);
})
