const humidity = document.querySelector('.humidityValue')
const temperature = document.querySelector('.tempValue')
const light = document.querySelector('.luxValue')
const weatherImage = document.querySelector('.weatherImageHolder')

function updateValue() {
    // humidity.innerHTML =
    // temperature.innerHTML =
    // light.innerHTML =
    if (isGoingToRain()) {
        weatherImage.innerHTML = `<img class="weatherImage" src="./images/storm.png" alt="storm"></img>`
    }

    else if (isDark()) {
        weatherImage.innerHTML = `<img class="weatherImage" src="./images/moon.png" alt="moon"></img>`
    }

    else {
        weatherImage.innerHTML = `<img class="weatherImage" src="./images/sunny.png" alt="sunny">`
    }
}