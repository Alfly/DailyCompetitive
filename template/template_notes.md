## [name]()

> Tag: 

### 方法一：
* 时间复杂度: $O()$
* 空间复杂度: $O()$
```c++

```

### 方法二：
* 时间复杂度: $O()$
* 空间复杂度: $O()$
```c++

```

## snippet setting in vscode

`markdown.json`: snippet setting
```json
	"Make code notes here": {
		"prefix": "notes",
		"body": [
			"## [name]()",
			"",
			"> Tag: ",
			"",
			"### 方法一：",
			"* 时间复杂度: $O()$",
			"* 空间复杂度: $O()$",
			"```c++",
			"",
			"```",
			"",
			"### 方法二：",
			"* 时间复杂度: $O()$",
			"* 空间复杂度: $O()$",
			"```c++",
			"",
			"```"
		],
		"description": "Make code notes here"
	}
```

`setting.json`: allow quick quickSuggestions in `*.md` files
```json
    "[markdown]": {
        "editor.quickSuggestions": {
          "other": true,
          "comments": true,
          "strings": true
        }
    }
```