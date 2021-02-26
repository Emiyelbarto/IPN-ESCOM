<template>
  <div>
    <nuxt />
  </div>
</template>

<style>
* {
  box-sizing: border-box;
}

body {
  font-family: 'open sans', helvetica, arial, sans;
  background: url(http://farm8.staticflickr.com/7064/6858179818_5d652f531c_h.jpg)
    no-repeat center center fixed;
  -webkit-background-size: cover;
  -moz-background-size: cover;
  -o-background-size: cover;
  background-size: cover;
}

.log-form {
  width: 40%;
  min-width: 320px;
  max-width: 475px;
  background: #fff;
  position: absolute;
  top: 50%;
  left: 50%;
  -webkit-transform: translate(-50%, -50%);
  -moz-transform: translate(-50%, -50%);
  -o-transform: translate(-50%, -50%);
  -ms-transform: translate(-50%, -50%);
  transform: translate(-50%, -50%);

  box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.25);

  @media (max-width: 40em) {
    width: 95%;
    position: relative;
    margin: 2.5% auto 0 auto;
    left: 0%;
    -webkit-transform: translate(0%, 0%);
    -moz-transform: translate(0%, 0%);
    -o-transform: translate(0%, 0%);
    -ms-transform: translate(0%, 0%);
    transform: translate(0%, 0%);
  }

  form {
    display: block;
    width: 100%;
    padding: 2em;
  }

  h2 {
    width: 100%;
    color: white;
    font-family: 'open sans condensed';
    font-size: 1.35em;
    display: block;
    background: blue;
    width: 100%;
    text-transform: uppercase;
    padding: 0.75em 1em 0.75em 1.5em;
    box-shadow: inset 0px 1px 1px fadeout(white, 95%);
    border: 1px solid darken(#2a2a2a, 5%);
    margin: 0;
    font-weight: 200;
  }

  input {
    display: block;
    margin: auto auto;
    width: 100%;
    margin-bottom: 2em;
    padding: 0.5em 0;
    border: none;
    border-bottom: 1px solid #eaeaea;
    padding-bottom: 1.25em;
    color: #757575;
  }
}
.forgot {
  color: lighten(#1fb5bf, 10%);
  line-height: 0.5em;
  position: relative;
  top: 1em;
  text-decoration: none;
  font-size: 0.75em;
  margin: 0;
  padding: 0;
  float: right;
}

.tablas--contenido {
  width: 60%;
  min-width: 320px;
  max-width: 8000px;
  background: #fff;
  position: absolute;
  top: 10%;
  left: 10%;

  h2 {
    width: 100%;
    color: white;
    font-family: 'open sans condensed';
    font-size: 1.1em;
    display: block;
    background: blue;
    text-transform: uppercase;
    padding: 0.75em 1em 0.75em 3em;
    box-shadow: inset 0px 10px 1px fadeout(white, 95%);
    border: 1px solid darken(#2a2a2a, 5%);
    margin: 0;
    font-weight: 100;
  }
  table {
    width: 80%;
    min-width: 320px;
    max-width: 800px;
  }
}
.input {
  display: block;
  margin: auto auto;
  width: 100%;
  margin-bottom: 2em;
  padding: 0.5em 0;
  border: none;
  border-bottom: 1px solid #eaeaea;
  padding-bottom: 1.25em;
  color: #757575;
}
</style>
