## [name]()

> Tag: 

### 方法一：
* 时间复杂度: ${O()}$
* 空间复杂度: ${O()}$
```cpp

```

### 方法二：
* 时间复杂度: ${O()}$
* 空间复杂度: ${O()}$
```cpp

```

## snippet setting in vscode

`cmd + shift + p` -> `Snippets: Configure User Snippets` -> `markdown.json`:
```json
	"Make code notes here": {
		"prefix": "notes",
		"body": [
			"## [name]()",
			"",
			"> Tag: ",
			"",
			"### 方法一：",
			"* 时间复杂度: ${O()}$",
			"* 空间复杂度: ${O()}$",
			"```cpp",
			"",
			"```",
			"",
			"### 方法二：",
			"* 时间复杂度: ${O()}$",
			"* 空间复杂度: ${O()}$",
			"```cpp",
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