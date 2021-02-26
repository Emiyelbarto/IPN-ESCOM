const jsonToFormData = (json) => {
  const formData = new FormData()

  for (const key in json) {
    const value = json[key]

    if (!Array.isArray(value)) {
      formData.append(key, value)
    } else {
      for (const item in value) {
        formData.append(`${key}[]`, value[item])
      }
    }
  }

  return formData
}

const toFormData = (obj, form, namespace) => {
  const fd = form || new FormData()
  let formKey

  for (const property in obj) {
    if (
      Object.prototype.hasOwnProperty.call(this, obj, property) &&
      obj[property]
    ) {
      if (namespace) {
        formKey = namespace + '[' + property + ']'
      } else {
        formKey = property
      }

      // if the property is an object, but not a File, use recursivity.
      if (obj[property] instanceof Date) {
        fd.append(formKey, obj[property].toISOString())
      } else if (
        typeof obj[property] === 'object' &&
        !(obj[property] instanceof File)
      ) {
        toFormData(obj[property], fd, formKey)
      } else {
        // if it's a string or a File object
        fd.append(formKey, obj[property])
      }
    }
  }

  return fd
}

const toBase64 = (file) =>
  new Promise((resolve, reject) => {
    const reader = new FileReader()
    reader.readAsDataURL(file)
    reader.onload = () => resolve(reader.result)
    reader.onerror = (error) => reject(error)
  })

export { toBase64, jsonToFormData, toFormData }
