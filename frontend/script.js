const humidity = document.querySelector('.humidityValue')
const temperature = document.querySelector('.tempValue')
const light = document.querySelector('.luxValue')
const weatherImage = document.querySelector('.weatherImageHolder')

function updateValue() {
    // TODO: Connect this data with database

    humidity.innerHTML = 75
    temperature.innerHTML = 27
    light.innerHTML = 300
    // End of ToDo
    if (light.innerHTML < 300) {
        weatherImage.innerHTML = `<img class="weatherImage" src="./images/moon.png" alt="moon"></img>`
    }

    else if (humidity.innerHTML > 70 && temperature.innerHTML > 25) {
        weatherImage.innerHTML = `<img class="weatherImage" src="./images/storm.png" alt="storm"></img>`
    }

    else {
        weatherImage.innerHTML = `<img class="weatherImage" src="./images/sunny.png" alt="sunny">`
    }
}

updateValue();